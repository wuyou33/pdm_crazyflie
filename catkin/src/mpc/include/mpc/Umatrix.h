// ----------------------------------------------------------------------------
// UMATRIX.H
// 
// DFJ-Labo Library : Universal Matrix-Calculation Class Library
// ----------------------------------------------------------------------------

#ifndef __UMATRIX_H__
#define __UMATRIX_H__


///////////////////////////////////////////////////////////////////////////////
// Notice
// This class CMatrix requires the class "CUArray".
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Include Files

#include "uarray.h"

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Global Definitions

///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// Declare Classes
template <class TYPE, class ARG_TYPE> class CUMatrix;
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CUMatrix

template <class TYPE, class ARG_TYPE>
class	CUMatrix
{
// ----- [ データメンバ ] -----
protected:
	CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>*	m_pData;

// ----- [ 関数メンバ : protected ] -----
protected:
	// 基本メモり操作（内部関数）
	int		_GetSizeRow(void) const;
	int		_GetSizeCol(void) const;
	int		_SetSize(int, int);
	int		_RemoveAt(int, int, int = 1, int = 1);
	int		_RemoveAll(void);

// ----- [ 関数メンバ : public ] -----
public:
	// 構築・消滅
	CUMatrix();
	CUMatrix(const CUMatrix<TYPE, ARG_TYPE>&);
	~CUMatrix();
	// 基本メモリ操作
	int		GetSize(int&, int&) const;
	int		GetSizeRow(void) const;
	int		GetSizeCol(void) const;
	int		SetSize(int, int);
	int		RemoveAt(int, int, int = 1, int = 1);
	int		RemoveAll(void);
	// データ操作
	TYPE	GetAt(int, int) const;
	TYPE&	ElementAt(int, int);
	CUMatrix<TYPE, ARG_TYPE>	Extract(int, int, int, int) const;
	int		SetAt(int, int, ARG_TYPE);
	int		SetAtGrow(int, int, ARG_TYPE);
	int		SetAt(int, int, const CUMatrix<TYPE, ARG_TYPE>&);
	int		SetAtGrow(int, int, const CUMatrix<TYPE, ARG_TYPE>&);
	int		SetAt(int, int, const TYPE*, int = -1, int = -1);
	int		SetAtGrow(int, int, const TYPE*, int = -1, int = -1);
	int		SetAllZero(void);
	int								Copy(const CUMatrix<TYPE, ARG_TYPE>&);
	const CUMatrix<TYPE, ARG_TYPE>&	operator =(const CUMatrix<TYPE, ARG_TYPE>&);
	CUMatrix<TYPE, ARG_TYPE>	operator +(const CUMatrix<TYPE, ARG_TYPE>&) const;
	CUMatrix<TYPE, ARG_TYPE>	operator -(const CUMatrix<TYPE, ARG_TYPE>&) const;
	CUMatrix<TYPE, ARG_TYPE>	operator *(const CUMatrix<TYPE, ARG_TYPE>&) const;
	CUMatrix<TYPE, ARG_TYPE>	operator *(ARG_TYPE) const;
	CUMatrix<TYPE, ARG_TYPE>	operator /(ARG_TYPE) const;
	const CUMatrix<TYPE, ARG_TYPE>&	operator +=(const CUMatrix<TYPE, ARG_TYPE>&);
	const CUMatrix<TYPE, ARG_TYPE>&	operator -=(const CUMatrix<TYPE, ARG_TYPE>&);
	const CUMatrix<TYPE, ARG_TYPE>&	operator *=(const CUMatrix<TYPE, ARG_TYPE>&);
	const CUMatrix<TYPE, ARG_TYPE>&	operator *=(ARG_TYPE);
	const CUMatrix<TYPE, ARG_TYPE>&	operator /=(ARG_TYPE);
	// 比較・抽出・検索・置換
	int		Compare(const CUMatrix<TYPE, ARG_TYPE>&) const;
	int		operator ==(const CUMatrix<TYPE, ARG_TYPE>&) const;
	int		operator !=(const CUMatrix<TYPE, ARG_TYPE>&) const;

	// その他演算
     CUMatrix<TYPE, ARG_TYPE> Inverse(void);            //逆行列演算

	// 拡張クラス作成支援（＊ 実際の機能は、別クラスでサポート。＊）
	const CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>*	GetData(void) const;
	CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>*		GetData(void);
};

///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CUMatrix ***** メンバ関数 *****
///////////////////////////////////////////////////////////////////////////////
// CUMatrix 構築・消滅

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE>::CUMatrix()
{	// <public> 構築
	// 構築
	this->m_pData	= new CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE>::CUMatrix(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> 構築
	// 構築
	this->m_pData	= new CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>;
	// 複写
	this->Copy(UMatrix);
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE>::~CUMatrix()
{	// <public> 消滅
	// 破棄
	delete this->m_pData;
}

///////////////////////////////////////////////////////////////////////////////
// CUMatrix 基本メモリ操作

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::_GetSizeRow(void) const
{	// <protected> 行数の取得（内部関数）
	return this->m_pData->GetSize();
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::_GetSizeCol(void) const
{	// <protected> 列数の取得（内部関数）
	if(this->m_pData->GetSize() == 0)
		return 0;
	else
		return this->m_pData->GetAt(0).GetSize();
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::_SetSize(int nRowSize, int nColSize)
{	// <protected> 行列の大きさの設定（内部関数）
	int		nCount1;

	// 検査
	if(nRowSize < 0 || nColSize < 0)
		return 0;	// 異常終了

	// 行数の設定
	this->m_pData->SetSize(nRowSize);
	// 列数の設定
	for(nCount1=0; nCount1<this->m_pData->GetSize(); ++nCount1)
		this->m_pData->ElementAt(nCount1).SetSize(nColSize);

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::_RemoveAt(int nRowIndex, int nColIndex, int nRowCount /* = 1 */, int nColCount /* = 1 */)
{	// <protected> 指定行・指定列の削除（内部関数）
	// 行の削除
	if(nRowIndex >= 0 && nRowCount > 0)
	{	// 行を削除する場合
		// 検査
		if(this->m_pData->GetSize() < (nRowIndex + nRowCount) )	// 存在しない行を削除しようとした場合
			return 0;	// 異常終了
		// 削除
		this->m_pData->RemoveAt(nRowIndex, nRowCount);
	}

	// 列の削除
	if(nColIndex >= 0 && nColCount > 0 && this->m_pData->GetSize() > 0)
	{	// 列を削除する場合（空である場合を除く）
		// 検査
		if(this->m_pData->GetAt(0).GetSize() < (nColIndex + nColCount) )	// 存在しない列を削除しようとした場合
			return 0;	// 異常終了
		// 削除
		if(nColIndex == 0 && this->m_pData->GetAt(0).GetSize() == nColCount)	// 全削除である場合
			this->m_pData->RemoveAll();
		else
		{	// 通常の削除である場合
			int		nCount1;

			for(nCount1=0; nCount1<this->m_pData->GetSize(); ++nCount1)
				this->m_pData->ElementAt(nCount1).RemoveAt(nColIndex, nColCount);
		}
	}

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::_RemoveAll(void)
{	// <protected> 全削除（内部関数）
	return this->m_pData->RemoveAll();
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::GetSize(int& nRowSize, int& nColSize) const
{	// <public> 行列の大きさの取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();
	return 1;
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::GetSizeRow(void) const
{	// <public> 行数の取得
	return this->_GetSizeRow();
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::GetSizeCol(void) const
{	// <public> 列数の取得
	return this->_GetSizeCol();
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::SetSize(int nRowSize, int nColSize)
{	// <public> 行列の大きさの設定
	return this->_SetSize(nRowSize, nColSize);
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::RemoveAt(int nRowIndex, int nColIndex, int nRowCount /* = 1 */, int nColCount /* = 1 */)
{	// <public> 指定行・指定列の削除
	return this->_RemoveAt(nRowIndex, nColIndex, nRowCount, nColCount);
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::RemoveAll(void)
{	// <public> 全削除
	return this->_RemoveAll();
}

///////////////////////////////////////////////////////////////////////////////
// CUMatrix データ操作

template <class TYPE, class ARG_TYPE>
TYPE CUMatrix<TYPE, ARG_TYPE>::GetAt(int nRowIndex, int nColIndex) const
{	// <public> 要素の取得
	return this->m_pData->GetAt(nRowIndex).GetAt(nColIndex);
}

template <class TYPE, class ARG_TYPE>
TYPE& CUMatrix<TYPE, ARG_TYPE>::ElementAt(int nRowIndex, int nColIndex)
{	// <public> 要素の取得
	return this->m_pData->ElementAt(nRowIndex).ElementAt(nColIndex);
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::Extract(int nRowIndex, int nRowSize, int nColIndex, int nColSize) const
{	// <public> 部分行列の取得
	CUMatrix<TYPE, ARG_TYPE>	Matrix;
	int		nCount1, nCount2;

	// 検査
	if(nRowIndex < 0)
		return Matrix;	// 異常終了
	if(nColIndex < 0)
		return Matrix;	// 異常終了

	// デフォルトの行数、列数の設定
	if(nRowSize <= 0)
		nRowSize	= this->_GetSizeRow() - nRowIndex;
	if(nColSize <= 0)
		nColSize	= this->_GetSizeCol() - nColIndex;

	// 検査
	if(nRowSize <= 0 || this->_GetSizeRow() < (nRowIndex + nRowSize) )	// 存在しない行を取得しようとした場合
		return Matrix;	// 異常終了
	if(nColSize <= 0 || this->_GetSizeCol() < (nColIndex + nColSize) )	// 存在しない列を取得しようとした場合
		return Matrix;	// 異常終了

	// 行列の大きさの設定
	Matrix._SetSize(nRowSize, nColSize);
	// 複写
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			Matrix.m_pData->ElementAt(nCount1).SetAt(nCount2, this->m_pData->GetAt(nRowIndex + nCount1).GetAt(nColIndex + nCount2) );
	}

	// 正常終了
	return Matrix;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAt(int nRowIndex, int nColIndex, ARG_TYPE Element)
{	// <public> 要素の設定
	// 検査
	if(nRowIndex < 0 || this->_GetSizeRow() <= nRowIndex)
		return 0;	// 異常終了
	if(nColIndex < 0 || this->_GetSizeCol() <= nColIndex)
		return 0;	// 異常終了

	// 要素の設定
	this->m_pData->ElementAt(nRowIndex).ElementAt(nColIndex)	= Element;
	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAtGrow(int nRowIndex, int nColIndex, ARG_TYPE Element)
{	// <public> 要素の設定（配列自動拡張）
	int		nNewRowSize, nNewColSize;
	int		nCount1;

	// 検査
	if(nRowIndex < 0)
		return 0;	// 異常終了
	if(nColIndex < 0)
		return 0;	// 異常終了

	// 行数の検査
	nNewRowSize	= this->_GetSizeRow();
	if(nNewRowSize <= nRowIndex)	// 行数を拡張する必要がある場合
		nNewRowSize	= nRowIndex +1;
	// 列数の検査
	nNewColSize	= this->_GetSizeCol();
	if(nNewColSize <= nColIndex)	// 列数を拡張する必要がある場合
		nNewColSize	= nColIndex +1;
	// 行列の大きさの設定
	this->_SetSize(nNewRowSize, nNewColSize);

	// 要素の設定
	this->m_pData->ElementAt(nRowIndex).ElementAt(nColIndex)	= Element;
	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAt(int nRowIndex, int nColIndex, const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> 要素の設定
	int		nCount1, nCount2;

	// 検査
	if(nRowIndex < 0 || this->_GetSizeRow() < (nRowIndex + UMatrix.GetSizeRow() ) )
		return 0;	// 異常終了
	if(nColIndex < 0 || this->_GetSizeCol() < (nColIndex + UMatrix.GetSizeCol() ) )
		return 0;	// 異常終了

	// 要素の設定
	for(nCount1=0; nCount1<UMatrix._GetSizeRow(); ++nCount1)
	{
		for(nCount2=0; nCount2<UMatrix._GetSizeCol(); ++nCount2)
			this->m_pData->ElementAt(nRowIndex + nCount1).ElementAt(nColIndex + nCount2)	= UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAtGrow(int nRowIndex, int nColIndex, const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> 要素の設定（配列自動拡張）
	int		nNewRowSize, nNewColSize;
	int		nCount1, nCount2;

	// 検査
	if(nRowIndex < 0)
		return 0;	// 異常終了
	if(nColIndex < 0)
		return 0;	// 異常終了

	// 行数の検査
	nNewRowSize	= this->_GetSizeRow();
	if(nNewRowSize < (nRowIndex + UMatrix._GetSizeRow() ) )	// 行数を拡張する必要がある場合
		nNewRowSize	= nRowIndex + UMatrix._GetSizeRow();
	// 列数の検査
	nNewColSize	= this->_GetSizeCol();
	if(nNewColSize < (nColIndex + UMatrix._GetSizeCol() ) )	// 列数を拡張する必要がある場合
		nNewColSize	= nColIndex + UMatrix._GetSizeCol();
	// 行列の大きさの設定
	this->_SetSize(nNewRowSize, nNewColSize);

	// 要素の設定
	for(nCount1=0; nCount1<UMatrix._GetSizeRow(); ++nCount1)
	{
		for(nCount2=0; nCount2<UMatrix._GetSizeCol(); ++nCount2)
			this->m_pData->ElementAt(nRowIndex + nCount1).ElementAt(nColIndex + nCount2)	= UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAt(int nRowIndex, int nColIndex, const TYPE* pElement, int nRowSize /* = -1 */, int nColSize /* = -1 */)
{	// <public> 要素の一括設定
	int		nStartIndex;
	int		nCount1, nCount2;

	// 行数、列数の取得
	if(nRowSize == -1 && nColSize == -1)
	{	// 行数、列数が明示的に指定されていない場合（→ 要素配列の先頭 2 バイトに行数、列数が入っており、続いて行列要素が入っている。）
		// 行数、列数の取得
		nRowSize	= (int)pElement[0];
		nColSize	= (int)pElement[1];
		// 行列要素開始インデックスの設定
		nStartIndex	= 2;
	}
	else	// 行数、列数が明示的に指定されている場合（→ 要素配列には行列要素のみが入っている。）
		nStartIndex	= 0;	// 行列要素開始インデックスの設定

	// 検査
	if(nRowIndex < 0 || this->_GetSizeRow() < (nRowIndex + nRowSize) )
		return 0;	// 異常終了
	if(nColIndex < 0 || this->_GetSizeCol() < (nColIndex + nColSize) )
		return 0;	// 異常終了

	// 要素の書き込み
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nRowIndex + nCount1).ElementAt(nColIndex + nCount2)	= pElement[nStartIndex + nCount1*nColSize + nCount2];
	}

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAtGrow(int nRowIndex, int nColIndex, const TYPE* pElement, int nRowSize /* = -1 */, int nColSize /* = -1 */)
{	// <public> 要素の一括設定（配列自動拡張）
	int		nNewRowSize, nNewColSize;
	int		nStartIndex;
	int		nCount1, nCount2;

	// 行数、列数の取得
	if(nRowSize == -1 && nColSize == -1)
	{	// 行数、列数が明示的に指定されていない場合（→ 要素配列の先頭 2 バイトに行数、列数が入っており、続いて行列要素が入っている。）
		// 行数、列数の取得
		nRowSize	= (int)pElement[0];
		nColSize	= (int)pElement[1];
		// 行列要素開始インデックスの設定
		nStartIndex	= 2;
	}
	else	// 行数、列数が明示的に指定されている場合（→ 要素配列には行列要素のみが入っている。）
		nStartIndex	= 0;	// 行列要素開始インデックスの設定

	// 検査
	if(nRowIndex < 0)
		return 0;	// 異常終了
	if(nColIndex < 0)
		return 0;	// 異常終了

	// 行数の検査
	nNewRowSize	= this->_GetSizeRow();
	if(nNewRowSize < (nRowIndex + nRowSize) )	// 行数を拡張する必要がある場合
		nNewRowSize	= nRowIndex + nRowSize;
	// 列数の検査
	nNewColSize	= this->_GetSizeCol();
	if(nNewColSize < (nColIndex + nColSize) )	// 列数を拡張する必要がある場合
		nNewColSize	= nColIndex + nColSize;
	// 行列の大きさの設定
	this->_SetSize(nNewRowSize, nNewColSize);

	// 要素の書き込み
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nRowIndex + nCount1).ElementAt(nColIndex + nCount2)	= pElement[nStartIndex + nCount1*nColSize + nCount2];
	}

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAllZero(void)
{	// <public> すべての要素への 0 の書き込み
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// 検査と行数・列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// 書き込み
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nCount1).ElementAt(nCount2)	= 0;
	}

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::Copy(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> 行列の複写
	// データの複写
	return this->m_pData->Copy(*UMatrix.m_pData);
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator =(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> 行列の複写
	// データの複写
	this->m_pData->Copy(*UMatrix.m_pData);
	// 正常終了
	return (const CUMatrix<TYPE, ARG_TYPE>&)*this;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::operator +(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> 加算
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// 行数、列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();
	// 検査
	if(nRowSize != UMatrix._GetSizeRow() )	// 行数が異なる場合
		return UMatrixResult;	// 異常終了
	if(nColSize != UMatrix._GetSizeCol() )	// 列数が異なる場合
		return UMatrixResult;	// 異常終了

	// 行列の大きさの設定
	UMatrixResult._SetSize(nRowSize, nColSize);
	// 演算
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	= this->m_pData->GetAt(nCount1).GetAt(nCount2) + UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// 正常終了
	return UMatrixResult;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::operator -(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> 減算
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// 行数、列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();
	// 検査
	if(nRowSize != UMatrix._GetSizeRow() )	// 行数が異なる場合
		return UMatrixResult;	// 異常終了
	if(nColSize != UMatrix._GetSizeCol() )	// 列数が異なる場合
		return UMatrixResult;	// 異常終了

	// 行列の大きさの設定
	UMatrixResult._SetSize(nRowSize, nColSize);
	// 演算
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	= this->m_pData->GetAt(nCount1).GetAt(nCount2) - UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// 正常終了
	return UMatrixResult;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::operator *(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> 乗算
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize, nItrSize;
	int		nCount1, nCount2, nCount3;

	// 行数、列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= UMatrix._GetSizeCol();
	nItrSize	= this->_GetSizeCol();
	// 検査
	if(nItrSize != UMatrix._GetSizeRow() )	// 左辺の列数と右辺の行数が異なる場合
		return UMatrixResult;	// 異常終了

	// 行列の大きさの設定
	UMatrixResult._SetSize(nRowSize, nColSize);
	// 演算
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
		{
			// 初期値の代入
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	= 0;

			for(nCount3=0; nCount3<nItrSize; ++nCount3)
				UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	+= this->m_pData->GetAt(nCount1).GetAt(nCount3) * UMatrix.m_pData->GetAt(nCount3).GetAt(nCount2);
		}
	}

	// 正常終了
	return UMatrixResult;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::operator *(ARG_TYPE Number) const
{	// <public> 乗算
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// 行数、列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// 演算結果行列の設定
	UMatrixResult.Copy(*this);
	// 演算
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	*= Number;
	}

	// 正常終了
	return UMatrixResult;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::operator /(ARG_TYPE Number) const
{	// <public> 除算
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// 行数、列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// 演算結果行列の設定
	UMatrixResult.Copy(*this);
	// 演算
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	/= Number;
	}

	// 正常終了
	return UMatrixResult;
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator +=(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> 加算代入
	int			nRowSize, nColSize;
	int			nCount1, nCount2;

	// 行数、列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();
	// 検査
/*	if(nRowSize != UMatrix._GetSizeRow() )	// 行数が異なる場合
		return UMatrixResult;	// 異常終了
	if(nColSize != UMatrix._GetSizeCol() )	// 列数が異なる場合
		return UMatrixResult;	// 異常終了
*/
	// 演算
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nCount1).ElementAt(nCount2) += UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// 正常終了
	return *this;
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator -=(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> 減算代入
	int			nRowSize, nColSize;
	int			nCount1, nCount2;

	// 行数、列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();
	// 検査
/*	if(nRowSize != UMatrix._GetSizeRow() )	// 行数が異なる場合				20160213 コメントアウト
		return UMatrixResult;	// 異常終了
	if(nColSize != UMatrix._GetSizeCol() )	// 列数が異なる場合
		return UMatrixResult;	// 異常終了
*/
	// 演算
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nCount1).ElementAt(nCount2) -= UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// 正常終了
	return *this;
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator *=(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> 乗算代入
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize, nItrSize;
	int		nCount1, nCount2, nCount3;

	// 行数、列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= UMatrix._GetSizeCol();
	nItrSize	= this->_GetSizeCol();
	// 検査
	if(nItrSize != UMatrix._GetSizeRow() )	// 左辺の列数と右辺の行数が異なる場合
		return UMatrixResult;	// 異常終了

	// 行列の大きさの設定
	UMatrixResult._SetSize(nRowSize, nColSize);
	// 演算
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
		{
			// 初期値の代入
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	= 0;

			for(nCount3=0; nCount3<nItrSize; ++nCount3)
				UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	+= this->m_pData->GetAt(nCount1).GetAt(nCount3) * UMatrix.m_pData->GetAt(nCount3).GetAt(nCount2);
		}
	}

	// 複写
	this->m_pData->Copy(*UMatrixResult.m_pData);
	// 正常終了
	return *this;
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator *=(ARG_TYPE Number)
{	// <public> 乗算代入
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// 行数・列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// 演算
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nCount1).ElementAt(nCount2)	*= Number;
	}

	// 正常終了
	return *this;
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator /=(ARG_TYPE Number)
{	// <public> 除算代入
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// 行数・列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// 演算
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nCount1).ElementAt(nCount2)	/= Number;
	}

	// 正常終了
	return *this;
}

///////////////////////////////////////////////////////////////////////////////
// CUMatrix その他演算

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::Inverse(void) 
{  //逆行列の演算

   CUMatrix<double, const double&> IMatrix;
   CUMatrix<double, const double&> IC;


   double P,Temp1,Temp2, Temp3;
   int Row,Col;
   int i,j,k;

   Row = this->_GetSizeRow();
   Col = this->_GetSizeCol();

   IC.SetSize(Row,Col);
   IC.SetAllZero();


   if(Row != Col)           //行列が正方でない場合
	   return IC;              //異常終了　

   IMatrix.SetSize(Row,Col);
   IMatrix.SetAllZero();

   for(i=0;i<Col;i++) IMatrix.SetAt(i,i,1.0);

   for(i=0;i<Col-1;i++){	      
		for(j=1+i;j<Col;j++){
			P = this->GetAt(j,i);
			for(k=0;k<Col;k++){

			Temp1 = this->GetAt(j,k);
			Temp2 = this->GetAt(i,k);
			Temp3 = this->GetAt(i,i);

			Temp1 -= Temp2*P/Temp3;

			this->SetAt(j,k,Temp1);

			Temp1 = IMatrix.GetAt(j,k);
			Temp2 = IMatrix.GetAt(i,k);

			Temp1 -= Temp2*P/Temp3;

			IMatrix.SetAt(j,k,Temp1);
        	
			}
		}
   }
    
   for(i=Col-1;i>0;i--){
  		for(j=i-1;j>-1;j--){
	  		P = this->GetAt(j,i);
			for(k=Col-1;k>-1;k--){
        	
			Temp1 = this->GetAt(j,k);
			Temp2 = this->GetAt(i,k);
			Temp3 = this->GetAt(i,i);

			Temp1 -= Temp2*P/Temp3;

			this->SetAt(j,k,Temp1);

			Temp1 = IMatrix.GetAt(j,k);
			Temp2 = IMatrix.GetAt(i,k);

			Temp1 -= Temp2*P/Temp3;

			IMatrix.SetAt(j,k,Temp1);
        	
			  }
		  }
   }
      
   for(i=0;i<Col;i++){
	   for(j=0;j<Col;j++){
            
		    Temp1 = this->GetAt(i,i);
			Temp2 = IMatrix.GetAt(i,j);
			Temp3 = Temp2/Temp1;

			IC.SetAt(i,j,Temp3);
	   }
   }

   return IC;
}



///////////////////////////////////////////////////////////////////////////////
// CUMatrix 比較・抽出・検索・置換

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::Compare(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> 比較
	int			nRowSize, nColSize;
	int			nCount1, nCount2;

	// 行数・列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// 行数・列数の比較
	if(nRowSize != UMatrix._GetSizeRow() )	// 行数が異なる場合
		return 1;
	if(nColSize != UMatrix._GetSizeCol() )	// 列数が異なる場合
		return 1;
	// 要素の比較
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
		{
			if(this->m_pData->GetAt(nCount1).GetAt(nCount2) != UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2) )	// 要素が異なる場合
				return 1;
		}
	}

	// 正常終了
	return 0;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::operator ==(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> 比較
	int			nRowSize, nColSize;
	int			nCount1, nCount2;

	// 行数・列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// 行数・列数の比較
	if(nRowSize != UMatrix._GetSizeRow() )	// 行数が異なる場合
		return 0;
	if(nColSize != UMatrix._GetSizeCol() )	// 列数が異なる場合
		return 0;
	// 要素の比較
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
		{
			if(this->m_pData->GetAt(nCount1).GetAt(nCount2) != UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2) )	// 要素が異なる場合
				return 0;
		}
	}

	// 正常終了
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::operator !=(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> 比較
	int			nRowSize, nColSize;
	int			nCount1, nCount2;

	// 行数・列数の取得
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// 行数・列数の比較
	if(nRowSize != UMatrix._GetSizeRow() )	// 行数が異なる場合
		return 1;
	if(nColSize != UMatrix._GetSizeCol() )	// 列数が異なる場合
		return 1;
	// 要素の比較
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
		{
			if(this->m_pData->GetAt(nCount1).GetAt(nCount2) != UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2) )	// 要素が異なる場合
				return 1;
		}
	}

	// 正常終了
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// CUMatrix 拡張クラス作成支援

template <class TYPE, class ARG_TYPE>
inline const CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>* CUMatrix<TYPE, ARG_TYPE>::GetData(void) const
{	// <public> データへのポインタの取得
	return this->m_pData;
}

template <class TYPE, class ARG_TYPE>
inline CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>* CUMatrix<TYPE, ARG_TYPE>::GetData(void)
{	// <public> データの配列へのポインタの取得
	return this->m_pData;
}

///////////////////////////////////////////////////////////////////////////////


#endif	// __UMATRIX_H__

// ----------------------------------------------------------------------------
// End of UMATRIX.H
// ----------------------------------------------------------------------------
