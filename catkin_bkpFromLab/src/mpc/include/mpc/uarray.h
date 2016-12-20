// ----------------------------------------------------------------------------
// UARRAY.H
// 
// DFJ-Labo Library : Universal Array Class Library
// ----------------------------------------------------------------------------

#ifndef __UARRAY_H__
#define __UARRAY_H__


///////////////////////////////////////////////////////////////////////////////
// Global Definitions

// NULL Pointer
#ifndef NULL
#ifdef __cplusplus
#define NULL	0
#else
#define NULL	((void *)0)
#endif
#endif

///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// Declare Classes
template <class TYPE, class ARG_TYPE> class CUArray;
template <class TYPE, class ARG_TYPE> class CUArrayData;
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CUArray

template <class TYPE, class ARG_TYPE>
class	CUArray
{
// ***** ! Notice ! *****
// Class TYPE must contain the members below :
// Copy-Constructor, operator =, operator ==, operator !=

// ----- [ データメンバ ] -----
protected:
	CUArrayData<TYPE, ARG_TYPE>*	m_pData;

// ----- [ 関数メンバ : protected ] -----
protected:
	// 参照カウンタ関連メモリ操作
	int		Detach(void);
	int		Attach(CUArrayData<TYPE, ARG_TYPE>*);
	int		Independence(void);

// ----- [ 関数メンバ : public ] -----
public:
	// 構築・消滅
	CUArray();
	CUArray(const CUArray<TYPE, ARG_TYPE>&);
	~CUArray();
	// 参照カウンタ関連メモリ操作
	// 基本メモリ操作 
	int		GetSize(void) const;
	int		SetSize(int);
	int		RemoveAt(int, int = 1);
	int		RemoveAll(void);
	int		FreeExtra(void);
	// データ操作
	TYPE	GetAt(int) const;
	TYPE&	ElementAt(int);
	TYPE	operator [](int) const;
	TYPE&	operator [](int);
	operator const TYPE*(void) const;
	int		SetAt(int, ARG_TYPE);
	int		SetAtGrow(int, ARG_TYPE);
	int								Copy(const CUArray<TYPE, ARG_TYPE>&);
	const CUArray<TYPE, ARG_TYPE>&	operator =(const CUArray<TYPE, ARG_TYPE>&);
	int		InsertAt(int, const CUArray<TYPE, ARG_TYPE>&);
	int		InsertAt(int, ARG_TYPE, int = 1);
	int								Add(const CUArray<TYPE, ARG_TYPE>&);
	int								Add(ARG_TYPE);
	const CUArray<TYPE, ARG_TYPE>&	operator +=(const CUArray<TYPE, ARG_TYPE>&);
	const CUArray<TYPE, ARG_TYPE>&	operator +=(ARG_TYPE);
	// 比較・抽出・検索・置換
	int		Compare(const CUArray<TYPE, ARG_TYPE>&) const;
	int		operator ==(const CUArray<TYPE, ARG_TYPE>&) const;
	int		operator !=(const CUArray<TYPE, ARG_TYPE>&) const;
	CUArray<TYPE, ARG_TYPE>			Left(int) const;
	CUArray<TYPE, ARG_TYPE>			Mid(int, int) const;
	CUArray<TYPE, ARG_TYPE>			Mid(int) const;
	CUArray<TYPE, ARG_TYPE>			Right(int) const;
	CUArray<TYPE, ARG_TYPE>			GetSpan(int&, ARG_TYPE) const;
	CUArray<TYPE, ARG_TYPE>			GetSpan(int&, const CUArray<TYPE, ARG_TYPE>&) const;
	int		Find(int&, ARG_TYPE) const;
	int		Find(int&, const CUArray<TYPE, ARG_TYPE>&) const;
	int		FindOneOf(int&, const CUArray<TYPE, ARG_TYPE>&) const;
	int		ReverseFind(int&, ARG_TYPE) const;
	int		Replace(ARG_TYPE, ARG_TYPE, int = 0, int = -1);
	int		ReplaceOneOf(ARG_TYPE, const CUArray<TYPE, ARG_TYPE>&, int = 0, int = -1);

	// 拡張クラス作成支援（＊ 実際の機能は、別クラスでサポート。＊）
	const TYPE*	GetData(void) const;
	TYPE*		GetData(void);
};

///////////////////////////////////////////////////////////////////////////////
// CUArray ***** メンバ関数 *****
///////////////////////////////////////////////////////////////////////////////
// CUArray 構築・消滅

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE>::CUArray()
{	// <public> 構築
	// 初期化
	this->m_pData	= NULL;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE>::CUArray(const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> 構築
	// 初期化
	this->m_pData	= NULL;
	// 複写
	this->Copy(UArray);
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE>::~CUArray()
{	// <public> 消滅
	// データの切り離し
	this->Detach();
}

///////////////////////////////////////////////////////////////////////////////
// CUArray 参照カウンタ関連メモリ操作

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Detach(void)
{	// <protected> 切り離し
	if(this->m_pData != NULL)
	{	// データを保持している場合
		// 参照カウンタの更新
		this->m_pData->DecRef();
		if(this->m_pData->GetRef() <= 0)
			delete this->m_pData;
		// 切り離し
		this->m_pData	= NULL;

		// 正常終了
		return 1;
	}
	else	// データを保持していない場合
		return 1;	// 正常終了
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Attach(CUArrayData<TYPE, ARG_TYPE>* pUArrayData)
{	// <protected> 結合
	if(this->m_pData != NULL)
	{	// データを保持している場合
		// 参照カウンタの更新
		this->m_pData->DecRef();
		if(this->m_pData->GetRef() <= 0)
			delete this->m_pData;
	}

	// 結合
	if(pUArrayData != NULL)
		pUArrayData->IncRef();
	this->m_pData	= pUArrayData;

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Independence(void)
{	// <protected> 独立
	if(this->m_pData != NULL)
	{	// データを保持している場合
		if(this->m_pData->GetRef() > 1)
		{	// データを他と共有している場合
			CUArrayData<TYPE, ARG_TYPE>*	pUArrayData;
			int		nCount1, nSize;

			// 新しいデータの作成
			pUArrayData	= new CUArrayData<TYPE, ARG_TYPE>;
			if(pUArrayData == NULL)
				return 0;	// 異常終了
			if(pUArrayData->SetSize(this->m_pData->GetSize() ) == 0)
				return 0;	// 異常終了
			// 複写
			TYPE* pSrcData	= this->m_pData->GetData();
			TYPE* pDestData	= pUArrayData->GetData();
			nSize		= this->m_pData->GetSize();
			for(nCount1=0; nCount1<nSize; ++nCount1)
				pDestData[nCount1]	= pSrcData[nCount1];
			// 元のデータの切り離し
			this->m_pData->DecRef();
			this->m_pData	= pUArrayData;
		}

		// 正常終了
		return 1;
	}
	else
	{	// データを保持していない場合
		// 新しいデータの作成
		this->m_pData	= new CUArrayData<TYPE, ARG_TYPE>;
		if(this->m_pData == NULL)
			return 0;	// 異常終了
		else
			return 1;	// 正常終了
	}
}

///////////////////////////////////////////////////////////////////////////////
// CUArray 基本メモリ操作

template <class TYPE, class ARG_TYPE>
inline int CUArray<TYPE, ARG_TYPE>::GetSize(void) const
{	// <public> 配列の大きさの取得
	if(this->m_pData == NULL)
		return 0;
	else
		return this->m_pData->GetSize();
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::SetSize(int nSize)
{	// <public> 配列の大きさの設定
	// 検査
	if(nSize < 0)
		return 0;	// 異常終了

	// 独立データの保持
	this->Independence();
	// 配列の大きさの設定
	return this->m_pData->SetSize(nSize);
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::RemoveAt(int nIndex, int nCount /* = 1 */)
{	// <public> 一部のデータの削除
	int		nSrcIndex, nDestIndex, nMoveCount;
	int		nCount1;

	// 検査
	if(this->m_pData == NULL)
		return 0;	// 異常終了
	if(nIndex < 0 || this->m_pData->GetSize() <= nIndex)
		return 0;	// 異常終了
	if(nCount < 1 || this->m_pData->GetSize() < (nIndex + nCount) )
		return 0;	// 異常終了

	// 独立データの保持
	this->Independence();

	// 移動するデータの特定
	nSrcIndex	= nIndex + nCount;
	nDestIndex	= nIndex;
	nMoveCount	= this->m_pData->GetSize() - nSrcIndex;
	// データの移動
	TYPE* pData	= this->m_pData->GetData();
	for(nCount1=0; nCount1<nMoveCount; ++nCount1, ++nSrcIndex, ++nDestIndex)
		pData[nDestIndex]	= pData[nSrcIndex];
	// 配列の大きさの設定
	return this->m_pData->SetSize(this->m_pData->GetSize() - nCount);
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::RemoveAll(void)
{	// <public> 全データの削除
	if(this->m_pData != NULL)
	{
		// 独立データの保持
		this->Independence();
		// 全データの削除
		return this->m_pData->SetSize(0);
	}
	else
		return 1;	// 正常終了
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::FreeExtra(void)
{	// <public> 余分なメモリの解放
	if(this->m_pData != NULL)
	{
		// 独立データの保持
		this->Independence();
		// 余分なメモリの解放
		return this->m_pData->FreeExtra();
	}
	else
		return 1;	// 正常終了
}

///////////////////////////////////////////////////////////////////////////////
// CUArray データ操作

template <class TYPE, class ARG_TYPE>
inline TYPE CUArray<TYPE, ARG_TYPE>::GetAt(int nIndex) const
{	// <public> 要素の取得
	return this->m_pData->GetData()[nIndex];
}

template <class TYPE, class ARG_TYPE>
inline TYPE& CUArray<TYPE, ARG_TYPE>::ElementAt(int nIndex)
{	// <public> 要素の取得
	this->Independence();
	return this->m_pData->GetData()[nIndex];
}

template <class TYPE, class ARG_TYPE>
inline TYPE CUArray<TYPE, ARG_TYPE>::operator [](int nIndex) const
{	// <public> 要素の取得
	return this->m_pData->GetData()[nIndex];
}

template <class TYPE, class ARG_TYPE>
inline TYPE& CUArray<TYPE, ARG_TYPE>::operator [](int nIndex)
{	// <public> 要素の取得
	this->Independence();
	return this->m_pData->GetData()[nIndex];
}

template <class TYPE, class ARG_TYPE>
inline CUArray<TYPE, ARG_TYPE>::operator const TYPE*(void) const
{	// <public> 現在のデータ配列へのポインタの取得
	return (const TYPE*)this->m_pData->GetData();
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::SetAt(int nIndex, ARG_TYPE Element)
{	// <public> 要素の設定
	// 検査
	if(nIndex < 0 || this->m_pData->GetSize() <= nIndex)
		return 0;	// 異常終了
	// 要素の設定
	if(this->Independence() == 0)
		return 0;	// 異常終了
	this->m_pData->GetData()[nIndex]	= Element;
	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::SetAtGrow(int nIndex, ARG_TYPE Element)
{	// <public> 要素の設定（必要ならば配列を拡張）
	// 検査
	if(nIndex < 0)
		return 0;	// 異常終了
	// 配列の拡張
	if(this->Independence() == 0)
		return 0;	// 異常終了
	if(this->m_pData->GetSize() <= nIndex)
	{
		if(this->m_pData->SetSize(nIndex +1) == 0)
			return 0;	// 異常終了
	}
	// 要素の設定
	this->m_pData->GetData()[nIndex]	= Element;
	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Copy(const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> 配列の複写
	// 現在の配列の切り離し
	this->Detach(); 
	// 配列の結合
	return this->Attach(UArray.m_pData);
}

template <class TYPE, class ARG_TYPE>
const CUArray<TYPE, ARG_TYPE>& CUArray<TYPE, ARG_TYPE>::operator =(const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> 配列の複写
	// 現在の配列の切り離し
	this->Detach();
	// 配列の結合
	this->Attach(UArray.m_pData);
	// 終了
	return (const CUArray<TYPE, ARG_TYPE>&)*this;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::InsertAt(int nIndex, const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> 配列の挿入
	int		nSrcIndex, nDestIndex, nMoveCount, nOldSize, nSrcSize;
	int		nCount1;

	// 検査
	if(nIndex < 0)
		return 0;	// 異常終了
	if(this->m_pData != NULL)
	{
		if(this->m_pData->GetSize() < nIndex)
			return 0;	// 異常終了
	}
	else
	{
		if(nIndex != 0)
			return 0;	// 異常終了
	}
	if(UArray.m_pData == NULL)
		return 1;	// 正常終了

	// データの独立化
	if(this->Independence() == 0)
		return 0;	// 異常終了
	// 配列の大きさの変更
	nOldSize	= this->m_pData->GetSize();
	if(this->m_pData->SetSize(this->m_pData->GetSize() + UArray.m_pData->GetSize() ) == 0)
		return 0;	// 異常終了
	// データの移動
	nSrcIndex	= nOldSize -1;
	nDestIndex	= this->m_pData->GetSize() -1;
	nMoveCount	= nOldSize - nIndex;
	nSrcSize	= UArray.m_pData->GetSize();
	TYPE* pSrcData	= UArray.m_pData->GetData();
	TYPE* pDestData	= this->m_pData->GetData();
	for(nCount1=0; nCount1<nMoveCount; ++nCount1, --nSrcIndex, --nDestIndex)
		pDestData[nDestIndex]	= pDestData[nSrcIndex];
	// データの挿入
	for(nCount1=0; nCount1<nSrcSize; ++nCount1)
		pDestData[nIndex + nCount1]	= pSrcData[nCount1];

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::InsertAt(int nIndex, ARG_TYPE Element, int nCount /* = 1 */)
{	// <public> 要素の挿入
	int		nSrcIndex, nDestIndex, nMoveCount, nOldSize;
	int		nCount1;

	// 検査
	if(nIndex < 0)
		return 0;	// 異常終了
	if(this->m_pData != NULL)
	{
		if(this->m_pData->GetSize() < nIndex)
			return 0;	// 異常終了
	}
	else
	{
		if(nIndex != 0)
			return 0;	// 異常終了
	}
	if(nCount < 0)
		return 0;	// 異常終了
	else if(nCount == 0)
		return 1;	// 正常終了


	// データの独立化
	if(this->Independence() == 0)
		return 0;	// 異常終了
	// 配列の大きさの変更
	nOldSize	= this->m_pData->GetSize();
	if(this->m_pData->SetSize(this->m_pData->GetSize() + nCount) == 0)
		return 0;	// 異常終了
	// データの移動
	nSrcIndex	= nOldSize -1;
	nDestIndex	= this->m_pData->GetSize() -1;
	nMoveCount	= nOldSize - nIndex;
	TYPE* pData	= this->m_pData->GetData();
	for(nCount1=0; nCount1<nMoveCount; ++nCount1, --nSrcIndex, --nDestIndex)
		pData[nDestIndex]	= pData[nSrcIndex];
	// データの挿入
	for(nCount1=0; nCount1<nCount; ++nCount1)
		pData[nIndex + nCount1]	= Element;

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Add(const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> 配列の追加
	int		nOldDestSize, nSrcSize;
	int		nCount1;

	// 検査
	if(UArray.m_pData == NULL)
	{
		// 正常終了
		if(this->m_pData == NULL)
			return 0;
		else
			return this->m_pData->GetSize();
	}

	// データの独立化
	if(this->Independence() == 0)
		return -1;	// 異常終了
	// 配列の大きさの変更
	nOldDestSize	= this->m_pData->GetSize();
	if(this->m_pData->SetSize(this->m_pData->GetSize() + UArray.m_pData->GetSize() ) == 0)
		return -1;	// 異常終了
	// データの追加
	nSrcSize	= UArray.m_pData->GetSize();
	TYPE* pSrcData	= UArray.m_pData->GetData();
	TYPE* pDestData	= this->m_pData->GetData();
	for(nCount1=0; nCount1<nSrcSize; ++nCount1)
		pDestData[nOldDestSize + nCount1]	= pSrcData[nCount1];

	// 正常終了
	return nOldDestSize;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Add(ARG_TYPE Element)
{	// <public> 要素の追加
	// データの独立化
	if(this->Independence() == 0)
		return -1;	// 異常終了
	// 配列の大きさの変更
	if(this->m_pData->SetSize(this->m_pData->GetSize() +1) == 0)
		return -1;	// 異常終了
	// データの追加
	TYPE* pData	= this->m_pData->GetData();
	pData[this->m_pData->GetSize() -1]	= Element;

	// 正常終了
	return (this->m_pData->GetSize() -1);
}

template <class TYPE, class ARG_TYPE>
const CUArray<TYPE, ARG_TYPE>& CUArray<TYPE, ARG_TYPE>::operator +=(const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> 配列の追加
	int		nOldDestSize, nSrcSize;
	int		nCount1;

	// 検査
	if(UArray.m_pData == NULL)
		return (const CUArray<TYPE, ARG_TYPE>&)this;	// 正常終了

	// データの独立化
	this->Independence();
	// 配列の大きさの変更
	nOldDestSize	= this->m_pData->GetSize();
	if(this->m_pData->SetSize(this->m_pData->GetSize() + UArray.m_pData->GetSize() ) == 0)
		return (const CUArray<TYPE, ARG_TYPE>&)this;	// 異常終了
	// データの追加
	nSrcSize	= UArray.m_pData->GetSize();
	TYPE* pSrcData	= UArray.m_pData->GetData();
	TYPE* pDestData	= this->m_pData->GetData();
	for(nCount1=0; nCount1<nSrcSize; ++nCount1)
		pDestData[nOldDestSize + nCount1]	= pSrcData[nCount1];

	// 正常終了
	return (const CUArray<TYPE, ARG_TYPE>&)this;
}

template <class TYPE, class ARG_TYPE>
const CUArray<TYPE, ARG_TYPE>& CUArray<TYPE, ARG_TYPE>::operator +=(ARG_TYPE Element)
{	// <public> 要素の追加
	// データの独立化
	this->Independence();
	// 配列の大きさの変更
	if(this->m_pData->SetSize(this->m_pData->GetSize() +1) == 0)
		return (const CUArray<TYPE, ARG_TYPE>&)this;	// 異常終了
	// データの追加
	TYPE* pData	= this->m_pData->GetData();
	pData[this->m_pData->GetSize() -1]	= Element;

	// 正常終了
	return (const CUArray<TYPE, ARG_TYPE>&)this;
}

///////////////////////////////////////////////////////////////////////////////
// CUArray 比較・抽出・検索・置換

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Compare(const CUArray<TYPE, ARG_TYPE>& UArray) const
{	// <public> 比較
	int		nSize;
	int		nCount1;

	// 配列の大きさの比較
	nSize	= this->m_pData->GetSize();
	if(nSize > UArray.m_pData->GetSize() )
		return 1;
	else if(nSize < UArray.m_pData->GetSize() )
		return -1;

	// 要素の比較
	const TYPE* pData1	= this->m_pData->GetData();
	const TYPE* pData2	= UArray.m_pData->GetData();
	for(nCount1=0; nCount1<nSize; ++nCount1)
	{
		if(pData1[nCount1] != pData2[nCount1])
			return 2;
	}
	return 0;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::operator ==(const CUArray<TYPE, ARG_TYPE>& UArray) const
{	// <public> 比較
	int		nSize;
	int		nCount1;

	// 配列の大きさの比較
	nSize	= this->m_pData->GetSize();
	if(nSize != UArray.m_pData->GetSize() )
		return 0;

	// 要素の比較
	const TYPE* pData1	= this->m_pData->GetData();
	const TYPE* pData2	= UArray.m_pData->GetData();
	for(nCount1=0; nCount1<nSize; ++nCount1)
	{
		if(pData1[nCount1] != pData2[nCount1])
			return 0;
	}
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::operator !=(const CUArray<TYPE, ARG_TYPE>& UArray) const
{	// <public> 比較
	int		nSize;
	int		nCount1;

	// 配列の大きさの比較
	nSize	= this->m_pData->GetSize();
	if(nSize != UArray.m_pData->GetSize() )
		return 1;

	// 要素の比較
	const TYPE* pData1	= this->m_pData->GetData();
	const TYPE* pData2	= UArray.m_pData->GetData();
	for(nCount1=0; nCount1<nSize; ++nCount1)
	{
		if(pData1[nCount1] != pData2[nCount1])
			return 1;
	}
	return 0;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::Left(int nCount) const
{	// 左から指定数の要素を持つ配列の取得
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nCount1;

	// 検査
	if(nCount < 0 || this->m_pData->GetSize() < nCount)
		return UArray;	// 異常終了
	else if(nCount == 0)
		return UArray;	// 正常終了

	// 配列の作成
	if(UArray.Independence() == 0)
		return UArray;	// 異常終了
	if(UArray.m_pData->SetSize(nCount) == 0)
		return UArray;	// 異常終了
	// 要素の複写
	TYPE* pSrcData	= this->m_pData->GetData();
	TYPE* pDestData	= UArray.m_pData->GetData();
	for(nCount1=0; nCount1<nCount; ++nCount1)
		pDestData[nCount1]	= pSrcData[nCount1];

	// 正常終了
	return UArray;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::Mid(int nIndex, int nCount) const
{	// 指定位置から指定数の要素を持つ配列の取得
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nCount1;

	// 検査
	if(nIndex < 0 || this->m_pData->GetSize() <= nIndex)
		return UArray;	// 異常終了
	if(nCount < 0 || this->m_pData->GetSize() < (nIndex + nCount) )
		return UArray;	// 異常終了
	else if(nCount == 0)
		return UArray;	// 正常終了

	// 配列の作成
	if(UArray.Independence() == 0)
		return UArray;	// 異常終了
	if(UArray.m_pData->SetSize(nCount) == 0)
		return UArray;	// 異常終了
	// 要素の複写
	TYPE* pSrcData	= this->m_pData->GetData();
	TYPE* pDestData	= UArray.m_pData->GetData();
	for(nCount1=0; nCount1<nCount; ++nCount1)
		pDestData[nCount1]	= pSrcData[nIndex + nCount1];

	// 正常終了
	return UArray;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::Mid(int nIndex) const
{	// 指定位置から後ろすべての要素を持つ配列の取得
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nCount;
	int		nCount1;

	// 検査
	if(nIndex < 0 || this->m_pData->GetSize() <= nIndex)
		return UArray;	// 異常終了

	// 取り出す要素数の計算
	nCount	= this->m_pData->GetSize() - nIndex;

	// 配列の作成
	if(UArray.Independence() == 0)
		return UArray;	// 異常終了
	if(UArray.m_pData->SetSize(nCount) == 0)
		return UArray;	// 異常終了
	// 要素の複写
	TYPE* pSrcData	= this->m_pData->GetData();
	TYPE* pDestData	= UArray.m_pData->GetData();
	for(nCount1=0; nCount1<nCount; ++nCount1)
		pDestData[nCount1]	= pSrcData[nIndex + nCount1];

	// 正常終了
	return UArray;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::Right(int nCount) const
{	// 右から指定数の要素を持つ配列の取得
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nStartIndex;
	int		nCount1;

	// 検査
	if(nCount < 0 || this->m_pData->GetSize() < nCount)
		return UArray;	// 異常終了
	else if(nCount == 0)
		return UArray;	// 正常終了

	// 配列の作成
	if(UArray.Independence() == 0)
		return UArray;	// 異常終了
	if(UArray.m_pData->SetSize(nCount) == 0)
		return UArray;	// 異常終了
	// 要素の複写
	TYPE* pSrcData	= this->m_pData->GetData();
	TYPE* pDestData	= UArray.m_pData->GetData();
	nStartIndex		= this->m_pData->GetSize() - nCount;
	for(nCount1=0; nCount1<nCount; ++nCount1)
		pDestData[nCount1]	= pSrcData[nStartIndex + nCount1];

	// 正常終了
	return UArray;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::GetSpan(int& nStartIndex, ARG_TYPE Delimiter) const
{	// <public> 指定されたデータで区切られた部分文字列の取得
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nThisSize, nResultSize;
	int		nCount1, nCount2;

	// 配列の大きさの取得
	nThisSize	= this->m_pData->GetSize();

	// 検査
	if(nStartIndex < -1 || nThisSize <= nStartIndex)
		return UArray;	// 異常終了
	else if((nThisSize -1) == nStartIndex)
	{	// データの末尾に到達する場合
		// 開始インデックスの更新
		nStartIndex		= -1;
		// 正常終了
		return UArray;
	}

	// 検索
	const TYPE* pThisData	= this->m_pData->GetData();
	for(nCount1=(nStartIndex +1); nCount1<nThisSize; ++nCount1)
	{
		if(pThisData[nCount1] == Delimiter)	// 一致するデータが見つかった場合
			break;
	}
	// データの抽出
	nResultSize	= nCount1 - nStartIndex -1;
	UArray.SetSize(nResultSize);
	TYPE* pResultData	= UArray.m_pData->GetData();
	for(nCount2=0; nCount2<nResultSize; ++nCount2)
		pResultData[nCount2]	= pThisData[nStartIndex +1 + nCount2];
	// 開始インデックスの更新
	if(nCount1 >= nThisSize)
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// 正常終了
	return UArray;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::GetSpan(int& nStartIndex, const CUArray<TYPE, ARG_TYPE>& Delimiter) const
{	// <public> 指定されたデータ群で区切られた部分文字列の取得
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nThisSize, nDelimiterSize, nResultSize;
	int		nCount1, nCount2, nCount3;

	// 配列の大きさの取得
	nThisSize		= this->m_pData->GetSize();
	nDelimiterSize	= Delimiter.m_pData->GetSize();

	// 検査
	if(nStartIndex < -1 || nThisSize <= nStartIndex)
		return UArray;	// 異常終了
	else if((nThisSize -1) == nStartIndex)
	{	// データの末尾に到達する場合
		// 開始インデックスの更新
		nStartIndex		= -1;
		// 正常終了
		return UArray;
	}
	if(nDelimiterSize <= 0)
		return UArray;	// 異常終了

	// 検索
	const TYPE* pThisData			= this->m_pData->GetData();
	const TYPE* pDelimiterData	= Delimiter.m_pData->GetData();
	for(nCount1=(nStartIndex +1); nCount1<nThisSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nDelimiterSize; ++nCount2)
		{
			if(pThisData[nCount1] == pDelimiterData[nCount2])	// 一致するデータが見つかった場合
				break;
		}
		if(nCount2 < nDelimiterSize)
			break;
	}
	// データの抽出
	nResultSize	= nCount1 - nStartIndex -1;
	UArray.SetSize(nResultSize);
	TYPE* pResultData	= UArray.m_pData->GetData();
	for(nCount3=0; nCount3<nResultSize; ++nCount3)
		pResultData[nCount3]	= pThisData[nStartIndex +1 + nCount3];
	// 開始インデックスの更新
	if(nCount1 >= nThisSize)
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// 正常終了
	return UArray;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Find(int& nStartIndex, ARG_TYPE DataFind) const
{	// <public> 検索
	int		nThisSize;
	int		nCount1;

	// 配列の大きさの取得
	nThisSize	= this->m_pData->GetSize();

	// 検査
	if(nStartIndex < -1 || nThisSize <= nStartIndex)
		return -1;	// 異常終了
	else if((nThisSize -1) == nStartIndex)
	{	// データの末尾に到達する場合
		// 開始インデックスの更新
		nStartIndex		= -1;
		// 正常終了
		return nStartIndex;
	}

	// 検索
	const TYPE* pThisData	= this->m_pData->GetData();
	for(nCount1=(nStartIndex +1); nCount1<nThisSize; ++nCount1)
	{
		if(pThisData[nCount1] == DataFind)	// 一致するデータが見つかった場合
			break;
	}
	// 開始インデックスの更新
	if(nCount1 >= nThisSize)
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// 正常終了
	return nStartIndex;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Find(int& nStartIndex, const CUArray<TYPE, ARG_TYPE>& DataStringFind) const
{	// <public> データ列に一致するデータの検索
	int		nThisSize, nDataStringSize;
	int		nCount1, nCount2;

	// 配列の大きさの取得
	nThisSize		= this->m_pData->GetSize();
	nDataStringSize	= DataStringFind.m_pData->GetSize();

	// 検査
	if(nDataStringSize <= 0)
		return -1;	// 異常終了
	if(nStartIndex < -1 || (nThisSize - nDataStringSize +1) < nStartIndex)
		return -1;	// 異常終了
	else if((nThisSize - nDataStringSize) == nStartIndex)
	{	// データの末尾に到達する場合
		// 開始インデックスの更新
		nStartIndex		= -1;
		// 正常終了
		return nStartIndex;
	}

	// 検索
	const TYPE* pThisData			= this->m_pData->GetData();
	const TYPE* pDataStringData	= DataStringFind.m_pData->GetData();
	for(nCount1=(nStartIndex +1); nCount1<(nThisSize - nDataStringSize +1); ++nCount1)
	{
		for(nCount2=0; nCount2<nDataStringSize; ++nCount2)
		{
			if(pThisData[nCount1 + nCount2] != pDataStringData[nCount2])	// 一致しないデータが見つかった場合
				break;
		}
		if(nCount2 >= nDataStringSize)
			break;
	}
	// 開始インデックスの更新
	if(nCount1 >= (nThisSize - nDataStringSize +1) )
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// 正常終了
	return nStartIndex;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::FindOneOf(int& nStartIndex, const CUArray<TYPE, ARG_TYPE>& DataSetFind) const
{	// <public> データセットのいずれかに一致するデータの検索
	int		nThisSize, nDataSetSize;
	int		nCount1, nCount2;

	// 配列の大きさの取得
	nThisSize		= this->m_pData->GetSize();
	nDataSetSize	= DataSetFind.m_pData->GetSize();

	// 検査
	if(nStartIndex < -1 || nThisSize <= nStartIndex)
		return -1;	// 異常終了
	else if((nThisSize -1) == nStartIndex)
	{	// データの末尾に到達する場合
		// 開始インデックスの更新
		nStartIndex		= -1;
		// 正常終了
		return nStartIndex;
	}
	if(nDataSetSize <= 0)
		return -1;	// 異常終了

	// 検索
	const TYPE* pThisData		= this->m_pData->GetData();
	const TYPE* pDataSetData	= DataSetFind.m_pData->GetData();
	for(nCount1=(nStartIndex +1); nCount1<nThisSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nDataSetSize; ++nCount2)
		{
			if(pThisData[nCount1] == pDataSetData[nCount2])	// 一致するデータが見つかった場合
				break;
		}
		if(nCount2 < nDataSetSize)
			break;
	}
	// 開始インデックスの更新
	if(nCount1 >= nThisSize)
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// 正常終了
	return nStartIndex;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::ReverseFind(int& nStartIndex, ARG_TYPE DataFind) const
{	// <public> 検索（逆方向）
	int		nThisSize;
	int		nCount1;

	// 配列の大きさの取得
	nThisSize	= this->m_pData->GetSize();

	// 検査
	if(nStartIndex < 0 || nThisSize < nStartIndex)
		return -1;	// 異常終了
	else if(0 == nStartIndex)
	{	// データの末尾に到達する場合
		// 開始インデックスの更新
		nStartIndex		= -1;
		// 正常終了
		return nStartIndex;
	}

	// 検索
	const TYPE* pThisData	= this->m_pData->GetData();
	for(nCount1=(nStartIndex -1); nCount1>=0; --nCount1)
	{
		if(pThisData[nCount1] == DataFind)	// 一致するデータが見つかった場合
			break;
	}
	// 開始インデックスの更新
	if(nCount1 < 0)
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// 正常終了
	return nStartIndex;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Replace(ARG_TYPE DataReplace, ARG_TYPE DataFind, int nStartIndex /* = 0 */, int nSize /* = -1 */)
{	// <public> 置換
	int		nCount1;

	// 検査
	if(nStartIndex < 0 || this->m_pData->GetSize() <= nStartIndex)
		return 0;	// 異常終了
	if(nSize < -1)
		return 0;	// 異常終了
	else if(nSize == -1)
		nSize	= this->m_pData->GetSize();
	else
	{
		nSize	+= nStartIndex;
		if(nSize > this->m_pData->GetSize() )
			return 0;	// 異常終了
	}

	// 検索
	TYPE* pThisData	= this->m_pData->GetData();
	for(nCount1=nStartIndex; nCount1<nSize; ++nCount1)
	{
		if(pThisData[nCount1] == DataFind)	// 一致するデータが見つかった場合
			pThisData[nCount1]	= DataReplace;
	}

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::ReplaceOneOf(ARG_TYPE DataReplace, const CUArray<TYPE, ARG_TYPE>& DataSetFind, int nStartIndex /* = 0 */, int nSize /* = -1 */)
{	// <public> データセットのいずれかに一致するデータの置換
	int		nDataSetSize;
	int		nCount1, nCount2;

	// 配列の大きさの取得
	nDataSetSize	= DataSetFind.m_pData->GetSize();

	// 検査
	if(nDataSetSize <= 0)
		return 0;	// 異常終了
	if(nStartIndex < 0 || this->m_pData->GetSize() <= nStartIndex)
		return 0;	// 異常終了
	if(nSize < -1)
		return 0;	// 異常終了
	else if(nSize == -1)
		nSize	= this->m_pData->GetSize();
	else
	{
		nSize	+= nStartIndex;
		if(nSize > this->m_pData->GetSize() )
			return 0;	// 異常終了
	}

	// 検索
	TYPE* pThisData			= this->m_pData->GetData();
	const TYPE* pDataSetData	= DataSetFind.m_pData->GetData();
	for(nCount1=nStartIndex; nCount1<nSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nDataSetSize; ++nCount2)
		{
			if(pThisData[nCount1] == pDataSetData[nCount2])
			{	// 一致するデータが見つかった場合
				pThisData[nCount1]	= DataReplace;
				break;
			}
		}
	}

	// 正常終了
	return 1;
}

///////////////////////////////////////////////////////////////////////////////
// CUArray 拡張クラス作成支援

template <class TYPE, class ARG_TYPE>
inline const TYPE* CUArray<TYPE, ARG_TYPE>::GetData(void) const
{	// <public> データの配列へのポインタの取得
	return (const TYPE*)this->m_pData->GetData();
}

template <class TYPE, class ARG_TYPE>
inline TYPE* CUArray<TYPE, ARG_TYPE>::GetData(void)
{	// <public> データの配列へのポインタの取得
	this->Independence();
	return this->m_pData->GetData();
}

///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CUArrayData

template <class TYPE, class ARG_TYPE>
class	CUArrayData
{
friend class CUArray<TYPE, ARG_TYPE>;
// ----- [ データメンバ ] -----
private:
	// データ
	TYPE*	m_pData;
	int		m_nSize;
	int		m_nMaxSize;
	// 参照カウンタ
	int		m_nRef;

// ----- [ 関数メンバ : private ] -----
private:

// ----- [ 関数メンバ : protected ] -----
protected:
	// 構築・消滅
	CUArrayData();
	~CUArrayData();
	// 基本データアクセス
	const TYPE*	GetData(void) const;
	TYPE*		GetData(void);
	int		GetSize(void) const;
	int		SetSize(int);
	int		FreeExtra(void);
	int		GetRef(void) const;
	int		IncRef(int = 1);
	int		DecRef(int = 1);

};

///////////////////////////////////////////////////////////////////////////////
// CUArrayData ***** メンバ関数 *****
///////////////////////////////////////////////////////////////////////////////
// CUArrayData 構築・消滅

template <class TYPE, class ARG_TYPE>
CUArrayData<TYPE, ARG_TYPE>::CUArrayData()
{	// <protected> 構築
	// 初期化
	this->m_pData		= NULL;
	this->m_nSize		= 0;
	this->m_nMaxSize	= 0;
	this->m_nRef		= 1;
}

template <class TYPE, class ARG_TYPE>
CUArrayData<TYPE, ARG_TYPE>::~CUArrayData()
{	// <protected> 消滅
	if(this->m_pData != NULL)
		delete [] this->m_pData;
}

///////////////////////////////////////////////////////////////////////////////
// CUArrayData 基本データアクセス

template <class TYPE, class ARG_TYPE>
inline const TYPE* CUArrayData<TYPE, ARG_TYPE>::GetData(void) const
{	// <protected> データへのポインタの取得
	return (const TYPE*)this->m_pData;
}

template <class TYPE, class ARG_TYPE>
inline TYPE* CUArrayData<TYPE, ARG_TYPE>::GetData(void)
{	// <protected> データへのポインタの取得
	return this->m_pData;
}

template <class TYPE, class ARG_TYPE>
inline int CUArrayData<TYPE, ARG_TYPE>::GetSize(void) const
{	// <protected> サイズの取得
	return this->m_nSize;
}

template <class TYPE, class ARG_TYPE>
int CUArrayData<TYPE, ARG_TYPE>::SetSize(int nSize)
{	// <protected> サイズの設定
	if(nSize < 0)	// サイズ指定が不正である場合
		return 0;	// 異常終了
	else if(nSize <= this->m_nMaxSize)
	{	// 既存のメモリ領域で足りる場合
		this->m_nSize	= nSize;
		return 1;	// 正常終了
	}
	else
	{	// 新たなメモリ領域を必要とする場合
		TYPE*	pData;
		int		nCount1;

		// メモリブロックの割り当て
		pData	= new TYPE[nSize];
		if(pData == NULL)
			return 0;	// 異常終了
		// 複写
		for(nCount1=0; nCount1<this->m_nSize; ++nCount1)
			pData[nCount1]	= this->m_pData[nCount1];
		// ポインタの書き換え
		delete [] this->m_pData;
		this->m_pData	= pData;
		// サイズの書き換え
		this->m_nSize		= nSize;
		this->m_nMaxSize	= nSize;

		// 正常終了
		return 1;
	}
}

template <class TYPE, class ARG_TYPE>
int CUArrayData<TYPE, ARG_TYPE>::FreeExtra(void)
{	// <protected> 余分なメモリの解放
	if(this->m_nSize == 0 && this->m_pData != NULL)
	{	// 全メモリの強制解放が必要である場合
		delete [] this->m_pData;
		this->m_pData		= NULL;
		this->m_nSize		= 0;
		this->m_nMaxSize	= 0;
	}
	else if(this->m_nSize != this->m_nMaxSize)
	{	// メモリの部分的強制解放が必要である場合
		TYPE*	pData;
		int		nCount1;

		// メモリブロックの割り当て
		pData	= new TYPE[this->m_nSize];
		if(pData == NULL)
			return 0;
		// 複写
		for(nCount1=0; nCount1<this->m_nSize; ++nCount1)
			pData[nCount1]	= this->m_pData[nCount1];
		// ポインタの書き換え
		delete [] this->m_pData;
		this->m_pData	= pData;
		// サイズの書き換え
		this->m_nMaxSize	= this->m_nSize;
	}

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
inline int CUArrayData<TYPE, ARG_TYPE>::GetRef(void) const
{	// <protected> 参照カウンタの取得
	return this->m_nRef;
}

template <class TYPE, class ARG_TYPE>
inline int CUArrayData<TYPE, ARG_TYPE>::IncRef(int nCount /* = 1 */)
{	// <protected> 参照カウンタの増加
	return (this->m_nRef += nCount);
}

template <class TYPE, class ARG_TYPE>
inline int CUArrayData<TYPE, ARG_TYPE>::DecRef(int nCount /* = 1 */)
{	// <protected> 参照カウンタの減少
	return (this->m_nRef -= nCount);
}

///////////////////////////////////////////////////////////////////////////////


#endif	// __UARRAY_H__

// ----------------------------------------------------------------------------
// End of UARRAY.H
// ----------------------------------------------------------------------------
