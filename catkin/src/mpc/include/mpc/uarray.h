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

// ----- [ �f�[�^�����o ] -----
protected:
	CUArrayData<TYPE, ARG_TYPE>*	m_pData;

// ----- [ �֐������o : protected ] -----
protected:
	// �Q�ƃJ�E���^�֘A����������
	int		Detach(void);
	int		Attach(CUArrayData<TYPE, ARG_TYPE>*);
	int		Independence(void);

// ----- [ �֐������o : public ] -----
public:
	// �\�z�E����
	CUArray();
	CUArray(const CUArray<TYPE, ARG_TYPE>&);
	~CUArray();
	// �Q�ƃJ�E���^�֘A����������
	// ��{���������� 
	int		GetSize(void) const;
	int		SetSize(int);
	int		RemoveAt(int, int = 1);
	int		RemoveAll(void);
	int		FreeExtra(void);
	// �f�[�^����
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
	// ��r�E���o�E�����E�u��
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

	// �g���N���X�쐬�x���i�� ���ۂ̋@�\�́A�ʃN���X�ŃT�|�[�g�B���j
	const TYPE*	GetData(void) const;
	TYPE*		GetData(void);
};

///////////////////////////////////////////////////////////////////////////////
// CUArray ***** �����o�֐� *****
///////////////////////////////////////////////////////////////////////////////
// CUArray �\�z�E����

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE>::CUArray()
{	// <public> �\�z
	// ������
	this->m_pData	= NULL;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE>::CUArray(const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> �\�z
	// ������
	this->m_pData	= NULL;
	// ����
	this->Copy(UArray);
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE>::~CUArray()
{	// <public> ����
	// �f�[�^�̐؂藣��
	this->Detach();
}

///////////////////////////////////////////////////////////////////////////////
// CUArray �Q�ƃJ�E���^�֘A����������

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Detach(void)
{	// <protected> �؂藣��
	if(this->m_pData != NULL)
	{	// �f�[�^��ێ����Ă���ꍇ
		// �Q�ƃJ�E���^�̍X�V
		this->m_pData->DecRef();
		if(this->m_pData->GetRef() <= 0)
			delete this->m_pData;
		// �؂藣��
		this->m_pData	= NULL;

		// ����I��
		return 1;
	}
	else	// �f�[�^��ێ����Ă��Ȃ��ꍇ
		return 1;	// ����I��
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Attach(CUArrayData<TYPE, ARG_TYPE>* pUArrayData)
{	// <protected> ����
	if(this->m_pData != NULL)
	{	// �f�[�^��ێ����Ă���ꍇ
		// �Q�ƃJ�E���^�̍X�V
		this->m_pData->DecRef();
		if(this->m_pData->GetRef() <= 0)
			delete this->m_pData;
	}

	// ����
	if(pUArrayData != NULL)
		pUArrayData->IncRef();
	this->m_pData	= pUArrayData;

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Independence(void)
{	// <protected> �Ɨ�
	if(this->m_pData != NULL)
	{	// �f�[�^��ێ����Ă���ꍇ
		if(this->m_pData->GetRef() > 1)
		{	// �f�[�^�𑼂Ƌ��L���Ă���ꍇ
			CUArrayData<TYPE, ARG_TYPE>*	pUArrayData;
			int		nCount1, nSize;

			// �V�����f�[�^�̍쐬
			pUArrayData	= new CUArrayData<TYPE, ARG_TYPE>;
			if(pUArrayData == NULL)
				return 0;	// �ُ�I��
			if(pUArrayData->SetSize(this->m_pData->GetSize() ) == 0)
				return 0;	// �ُ�I��
			// ����
			TYPE* pSrcData	= this->m_pData->GetData();
			TYPE* pDestData	= pUArrayData->GetData();
			nSize		= this->m_pData->GetSize();
			for(nCount1=0; nCount1<nSize; ++nCount1)
				pDestData[nCount1]	= pSrcData[nCount1];
			// ���̃f�[�^�̐؂藣��
			this->m_pData->DecRef();
			this->m_pData	= pUArrayData;
		}

		// ����I��
		return 1;
	}
	else
	{	// �f�[�^��ێ����Ă��Ȃ��ꍇ
		// �V�����f�[�^�̍쐬
		this->m_pData	= new CUArrayData<TYPE, ARG_TYPE>;
		if(this->m_pData == NULL)
			return 0;	// �ُ�I��
		else
			return 1;	// ����I��
	}
}

///////////////////////////////////////////////////////////////////////////////
// CUArray ��{����������

template <class TYPE, class ARG_TYPE>
inline int CUArray<TYPE, ARG_TYPE>::GetSize(void) const
{	// <public> �z��̑傫���̎擾
	if(this->m_pData == NULL)
		return 0;
	else
		return this->m_pData->GetSize();
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::SetSize(int nSize)
{	// <public> �z��̑傫���̐ݒ�
	// ����
	if(nSize < 0)
		return 0;	// �ُ�I��

	// �Ɨ��f�[�^�̕ێ�
	this->Independence();
	// �z��̑傫���̐ݒ�
	return this->m_pData->SetSize(nSize);
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::RemoveAt(int nIndex, int nCount /* = 1 */)
{	// <public> �ꕔ�̃f�[�^�̍폜
	int		nSrcIndex, nDestIndex, nMoveCount;
	int		nCount1;

	// ����
	if(this->m_pData == NULL)
		return 0;	// �ُ�I��
	if(nIndex < 0 || this->m_pData->GetSize() <= nIndex)
		return 0;	// �ُ�I��
	if(nCount < 1 || this->m_pData->GetSize() < (nIndex + nCount) )
		return 0;	// �ُ�I��

	// �Ɨ��f�[�^�̕ێ�
	this->Independence();

	// �ړ�����f�[�^�̓���
	nSrcIndex	= nIndex + nCount;
	nDestIndex	= nIndex;
	nMoveCount	= this->m_pData->GetSize() - nSrcIndex;
	// �f�[�^�̈ړ�
	TYPE* pData	= this->m_pData->GetData();
	for(nCount1=0; nCount1<nMoveCount; ++nCount1, ++nSrcIndex, ++nDestIndex)
		pData[nDestIndex]	= pData[nSrcIndex];
	// �z��̑傫���̐ݒ�
	return this->m_pData->SetSize(this->m_pData->GetSize() - nCount);
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::RemoveAll(void)
{	// <public> �S�f�[�^�̍폜
	if(this->m_pData != NULL)
	{
		// �Ɨ��f�[�^�̕ێ�
		this->Independence();
		// �S�f�[�^�̍폜
		return this->m_pData->SetSize(0);
	}
	else
		return 1;	// ����I��
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::FreeExtra(void)
{	// <public> �]���ȃ������̉��
	if(this->m_pData != NULL)
	{
		// �Ɨ��f�[�^�̕ێ�
		this->Independence();
		// �]���ȃ������̉��
		return this->m_pData->FreeExtra();
	}
	else
		return 1;	// ����I��
}

///////////////////////////////////////////////////////////////////////////////
// CUArray �f�[�^����

template <class TYPE, class ARG_TYPE>
inline TYPE CUArray<TYPE, ARG_TYPE>::GetAt(int nIndex) const
{	// <public> �v�f�̎擾
	return this->m_pData->GetData()[nIndex];
}

template <class TYPE, class ARG_TYPE>
inline TYPE& CUArray<TYPE, ARG_TYPE>::ElementAt(int nIndex)
{	// <public> �v�f�̎擾
	this->Independence();
	return this->m_pData->GetData()[nIndex];
}

template <class TYPE, class ARG_TYPE>
inline TYPE CUArray<TYPE, ARG_TYPE>::operator [](int nIndex) const
{	// <public> �v�f�̎擾
	return this->m_pData->GetData()[nIndex];
}

template <class TYPE, class ARG_TYPE>
inline TYPE& CUArray<TYPE, ARG_TYPE>::operator [](int nIndex)
{	// <public> �v�f�̎擾
	this->Independence();
	return this->m_pData->GetData()[nIndex];
}

template <class TYPE, class ARG_TYPE>
inline CUArray<TYPE, ARG_TYPE>::operator const TYPE*(void) const
{	// <public> ���݂̃f�[�^�z��ւ̃|�C���^�̎擾
	return (const TYPE*)this->m_pData->GetData();
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::SetAt(int nIndex, ARG_TYPE Element)
{	// <public> �v�f�̐ݒ�
	// ����
	if(nIndex < 0 || this->m_pData->GetSize() <= nIndex)
		return 0;	// �ُ�I��
	// �v�f�̐ݒ�
	if(this->Independence() == 0)
		return 0;	// �ُ�I��
	this->m_pData->GetData()[nIndex]	= Element;
	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::SetAtGrow(int nIndex, ARG_TYPE Element)
{	// <public> �v�f�̐ݒ�i�K�v�Ȃ�Δz����g���j
	// ����
	if(nIndex < 0)
		return 0;	// �ُ�I��
	// �z��̊g��
	if(this->Independence() == 0)
		return 0;	// �ُ�I��
	if(this->m_pData->GetSize() <= nIndex)
	{
		if(this->m_pData->SetSize(nIndex +1) == 0)
			return 0;	// �ُ�I��
	}
	// �v�f�̐ݒ�
	this->m_pData->GetData()[nIndex]	= Element;
	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Copy(const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> �z��̕���
	// ���݂̔z��̐؂藣��
	this->Detach(); 
	// �z��̌���
	return this->Attach(UArray.m_pData);
}

template <class TYPE, class ARG_TYPE>
const CUArray<TYPE, ARG_TYPE>& CUArray<TYPE, ARG_TYPE>::operator =(const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> �z��̕���
	// ���݂̔z��̐؂藣��
	this->Detach();
	// �z��̌���
	this->Attach(UArray.m_pData);
	// �I��
	return (const CUArray<TYPE, ARG_TYPE>&)*this;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::InsertAt(int nIndex, const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> �z��̑}��
	int		nSrcIndex, nDestIndex, nMoveCount, nOldSize, nSrcSize;
	int		nCount1;

	// ����
	if(nIndex < 0)
		return 0;	// �ُ�I��
	if(this->m_pData != NULL)
	{
		if(this->m_pData->GetSize() < nIndex)
			return 0;	// �ُ�I��
	}
	else
	{
		if(nIndex != 0)
			return 0;	// �ُ�I��
	}
	if(UArray.m_pData == NULL)
		return 1;	// ����I��

	// �f�[�^�̓Ɨ���
	if(this->Independence() == 0)
		return 0;	// �ُ�I��
	// �z��̑傫���̕ύX
	nOldSize	= this->m_pData->GetSize();
	if(this->m_pData->SetSize(this->m_pData->GetSize() + UArray.m_pData->GetSize() ) == 0)
		return 0;	// �ُ�I��
	// �f�[�^�̈ړ�
	nSrcIndex	= nOldSize -1;
	nDestIndex	= this->m_pData->GetSize() -1;
	nMoveCount	= nOldSize - nIndex;
	nSrcSize	= UArray.m_pData->GetSize();
	TYPE* pSrcData	= UArray.m_pData->GetData();
	TYPE* pDestData	= this->m_pData->GetData();
	for(nCount1=0; nCount1<nMoveCount; ++nCount1, --nSrcIndex, --nDestIndex)
		pDestData[nDestIndex]	= pDestData[nSrcIndex];
	// �f�[�^�̑}��
	for(nCount1=0; nCount1<nSrcSize; ++nCount1)
		pDestData[nIndex + nCount1]	= pSrcData[nCount1];

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::InsertAt(int nIndex, ARG_TYPE Element, int nCount /* = 1 */)
{	// <public> �v�f�̑}��
	int		nSrcIndex, nDestIndex, nMoveCount, nOldSize;
	int		nCount1;

	// ����
	if(nIndex < 0)
		return 0;	// �ُ�I��
	if(this->m_pData != NULL)
	{
		if(this->m_pData->GetSize() < nIndex)
			return 0;	// �ُ�I��
	}
	else
	{
		if(nIndex != 0)
			return 0;	// �ُ�I��
	}
	if(nCount < 0)
		return 0;	// �ُ�I��
	else if(nCount == 0)
		return 1;	// ����I��


	// �f�[�^�̓Ɨ���
	if(this->Independence() == 0)
		return 0;	// �ُ�I��
	// �z��̑傫���̕ύX
	nOldSize	= this->m_pData->GetSize();
	if(this->m_pData->SetSize(this->m_pData->GetSize() + nCount) == 0)
		return 0;	// �ُ�I��
	// �f�[�^�̈ړ�
	nSrcIndex	= nOldSize -1;
	nDestIndex	= this->m_pData->GetSize() -1;
	nMoveCount	= nOldSize - nIndex;
	TYPE* pData	= this->m_pData->GetData();
	for(nCount1=0; nCount1<nMoveCount; ++nCount1, --nSrcIndex, --nDestIndex)
		pData[nDestIndex]	= pData[nSrcIndex];
	// �f�[�^�̑}��
	for(nCount1=0; nCount1<nCount; ++nCount1)
		pData[nIndex + nCount1]	= Element;

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Add(const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> �z��̒ǉ�
	int		nOldDestSize, nSrcSize;
	int		nCount1;

	// ����
	if(UArray.m_pData == NULL)
	{
		// ����I��
		if(this->m_pData == NULL)
			return 0;
		else
			return this->m_pData->GetSize();
	}

	// �f�[�^�̓Ɨ���
	if(this->Independence() == 0)
		return -1;	// �ُ�I��
	// �z��̑傫���̕ύX
	nOldDestSize	= this->m_pData->GetSize();
	if(this->m_pData->SetSize(this->m_pData->GetSize() + UArray.m_pData->GetSize() ) == 0)
		return -1;	// �ُ�I��
	// �f�[�^�̒ǉ�
	nSrcSize	= UArray.m_pData->GetSize();
	TYPE* pSrcData	= UArray.m_pData->GetData();
	TYPE* pDestData	= this->m_pData->GetData();
	for(nCount1=0; nCount1<nSrcSize; ++nCount1)
		pDestData[nOldDestSize + nCount1]	= pSrcData[nCount1];

	// ����I��
	return nOldDestSize;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Add(ARG_TYPE Element)
{	// <public> �v�f�̒ǉ�
	// �f�[�^�̓Ɨ���
	if(this->Independence() == 0)
		return -1;	// �ُ�I��
	// �z��̑傫���̕ύX
	if(this->m_pData->SetSize(this->m_pData->GetSize() +1) == 0)
		return -1;	// �ُ�I��
	// �f�[�^�̒ǉ�
	TYPE* pData	= this->m_pData->GetData();
	pData[this->m_pData->GetSize() -1]	= Element;

	// ����I��
	return (this->m_pData->GetSize() -1);
}

template <class TYPE, class ARG_TYPE>
const CUArray<TYPE, ARG_TYPE>& CUArray<TYPE, ARG_TYPE>::operator +=(const CUArray<TYPE, ARG_TYPE>& UArray)
{	// <public> �z��̒ǉ�
	int		nOldDestSize, nSrcSize;
	int		nCount1;

	// ����
	if(UArray.m_pData == NULL)
		return (const CUArray<TYPE, ARG_TYPE>&)this;	// ����I��

	// �f�[�^�̓Ɨ���
	this->Independence();
	// �z��̑傫���̕ύX
	nOldDestSize	= this->m_pData->GetSize();
	if(this->m_pData->SetSize(this->m_pData->GetSize() + UArray.m_pData->GetSize() ) == 0)
		return (const CUArray<TYPE, ARG_TYPE>&)this;	// �ُ�I��
	// �f�[�^�̒ǉ�
	nSrcSize	= UArray.m_pData->GetSize();
	TYPE* pSrcData	= UArray.m_pData->GetData();
	TYPE* pDestData	= this->m_pData->GetData();
	for(nCount1=0; nCount1<nSrcSize; ++nCount1)
		pDestData[nOldDestSize + nCount1]	= pSrcData[nCount1];

	// ����I��
	return (const CUArray<TYPE, ARG_TYPE>&)this;
}

template <class TYPE, class ARG_TYPE>
const CUArray<TYPE, ARG_TYPE>& CUArray<TYPE, ARG_TYPE>::operator +=(ARG_TYPE Element)
{	// <public> �v�f�̒ǉ�
	// �f�[�^�̓Ɨ���
	this->Independence();
	// �z��̑傫���̕ύX
	if(this->m_pData->SetSize(this->m_pData->GetSize() +1) == 0)
		return (const CUArray<TYPE, ARG_TYPE>&)this;	// �ُ�I��
	// �f�[�^�̒ǉ�
	TYPE* pData	= this->m_pData->GetData();
	pData[this->m_pData->GetSize() -1]	= Element;

	// ����I��
	return (const CUArray<TYPE, ARG_TYPE>&)this;
}

///////////////////////////////////////////////////////////////////////////////
// CUArray ��r�E���o�E�����E�u��

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Compare(const CUArray<TYPE, ARG_TYPE>& UArray) const
{	// <public> ��r
	int		nSize;
	int		nCount1;

	// �z��̑傫���̔�r
	nSize	= this->m_pData->GetSize();
	if(nSize > UArray.m_pData->GetSize() )
		return 1;
	else if(nSize < UArray.m_pData->GetSize() )
		return -1;

	// �v�f�̔�r
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
{	// <public> ��r
	int		nSize;
	int		nCount1;

	// �z��̑傫���̔�r
	nSize	= this->m_pData->GetSize();
	if(nSize != UArray.m_pData->GetSize() )
		return 0;

	// �v�f�̔�r
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
{	// <public> ��r
	int		nSize;
	int		nCount1;

	// �z��̑傫���̔�r
	nSize	= this->m_pData->GetSize();
	if(nSize != UArray.m_pData->GetSize() )
		return 1;

	// �v�f�̔�r
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
{	// ������w�萔�̗v�f�����z��̎擾
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nCount1;

	// ����
	if(nCount < 0 || this->m_pData->GetSize() < nCount)
		return UArray;	// �ُ�I��
	else if(nCount == 0)
		return UArray;	// ����I��

	// �z��̍쐬
	if(UArray.Independence() == 0)
		return UArray;	// �ُ�I��
	if(UArray.m_pData->SetSize(nCount) == 0)
		return UArray;	// �ُ�I��
	// �v�f�̕���
	TYPE* pSrcData	= this->m_pData->GetData();
	TYPE* pDestData	= UArray.m_pData->GetData();
	for(nCount1=0; nCount1<nCount; ++nCount1)
		pDestData[nCount1]	= pSrcData[nCount1];

	// ����I��
	return UArray;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::Mid(int nIndex, int nCount) const
{	// �w��ʒu����w�萔�̗v�f�����z��̎擾
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nCount1;

	// ����
	if(nIndex < 0 || this->m_pData->GetSize() <= nIndex)
		return UArray;	// �ُ�I��
	if(nCount < 0 || this->m_pData->GetSize() < (nIndex + nCount) )
		return UArray;	// �ُ�I��
	else if(nCount == 0)
		return UArray;	// ����I��

	// �z��̍쐬
	if(UArray.Independence() == 0)
		return UArray;	// �ُ�I��
	if(UArray.m_pData->SetSize(nCount) == 0)
		return UArray;	// �ُ�I��
	// �v�f�̕���
	TYPE* pSrcData	= this->m_pData->GetData();
	TYPE* pDestData	= UArray.m_pData->GetData();
	for(nCount1=0; nCount1<nCount; ++nCount1)
		pDestData[nCount1]	= pSrcData[nIndex + nCount1];

	// ����I��
	return UArray;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::Mid(int nIndex) const
{	// �w��ʒu�����낷�ׂĂ̗v�f�����z��̎擾
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nCount;
	int		nCount1;

	// ����
	if(nIndex < 0 || this->m_pData->GetSize() <= nIndex)
		return UArray;	// �ُ�I��

	// ���o���v�f���̌v�Z
	nCount	= this->m_pData->GetSize() - nIndex;

	// �z��̍쐬
	if(UArray.Independence() == 0)
		return UArray;	// �ُ�I��
	if(UArray.m_pData->SetSize(nCount) == 0)
		return UArray;	// �ُ�I��
	// �v�f�̕���
	TYPE* pSrcData	= this->m_pData->GetData();
	TYPE* pDestData	= UArray.m_pData->GetData();
	for(nCount1=0; nCount1<nCount; ++nCount1)
		pDestData[nCount1]	= pSrcData[nIndex + nCount1];

	// ����I��
	return UArray;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::Right(int nCount) const
{	// �E����w�萔�̗v�f�����z��̎擾
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nStartIndex;
	int		nCount1;

	// ����
	if(nCount < 0 || this->m_pData->GetSize() < nCount)
		return UArray;	// �ُ�I��
	else if(nCount == 0)
		return UArray;	// ����I��

	// �z��̍쐬
	if(UArray.Independence() == 0)
		return UArray;	// �ُ�I��
	if(UArray.m_pData->SetSize(nCount) == 0)
		return UArray;	// �ُ�I��
	// �v�f�̕���
	TYPE* pSrcData	= this->m_pData->GetData();
	TYPE* pDestData	= UArray.m_pData->GetData();
	nStartIndex		= this->m_pData->GetSize() - nCount;
	for(nCount1=0; nCount1<nCount; ++nCount1)
		pDestData[nCount1]	= pSrcData[nStartIndex + nCount1];

	// ����I��
	return UArray;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::GetSpan(int& nStartIndex, ARG_TYPE Delimiter) const
{	// <public> �w�肳�ꂽ�f�[�^�ŋ�؂�ꂽ����������̎擾
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nThisSize, nResultSize;
	int		nCount1, nCount2;

	// �z��̑傫���̎擾
	nThisSize	= this->m_pData->GetSize();

	// ����
	if(nStartIndex < -1 || nThisSize <= nStartIndex)
		return UArray;	// �ُ�I��
	else if((nThisSize -1) == nStartIndex)
	{	// �f�[�^�̖����ɓ��B����ꍇ
		// �J�n�C���f�b�N�X�̍X�V
		nStartIndex		= -1;
		// ����I��
		return UArray;
	}

	// ����
	const TYPE* pThisData	= this->m_pData->GetData();
	for(nCount1=(nStartIndex +1); nCount1<nThisSize; ++nCount1)
	{
		if(pThisData[nCount1] == Delimiter)	// ��v����f�[�^�����������ꍇ
			break;
	}
	// �f�[�^�̒��o
	nResultSize	= nCount1 - nStartIndex -1;
	UArray.SetSize(nResultSize);
	TYPE* pResultData	= UArray.m_pData->GetData();
	for(nCount2=0; nCount2<nResultSize; ++nCount2)
		pResultData[nCount2]	= pThisData[nStartIndex +1 + nCount2];
	// �J�n�C���f�b�N�X�̍X�V
	if(nCount1 >= nThisSize)
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// ����I��
	return UArray;
}

template <class TYPE, class ARG_TYPE>
CUArray<TYPE, ARG_TYPE> CUArray<TYPE, ARG_TYPE>::GetSpan(int& nStartIndex, const CUArray<TYPE, ARG_TYPE>& Delimiter) const
{	// <public> �w�肳�ꂽ�f�[�^�Q�ŋ�؂�ꂽ����������̎擾
	CUArray<TYPE, ARG_TYPE>		UArray;
	int		nThisSize, nDelimiterSize, nResultSize;
	int		nCount1, nCount2, nCount3;

	// �z��̑傫���̎擾
	nThisSize		= this->m_pData->GetSize();
	nDelimiterSize	= Delimiter.m_pData->GetSize();

	// ����
	if(nStartIndex < -1 || nThisSize <= nStartIndex)
		return UArray;	// �ُ�I��
	else if((nThisSize -1) == nStartIndex)
	{	// �f�[�^�̖����ɓ��B����ꍇ
		// �J�n�C���f�b�N�X�̍X�V
		nStartIndex		= -1;
		// ����I��
		return UArray;
	}
	if(nDelimiterSize <= 0)
		return UArray;	// �ُ�I��

	// ����
	const TYPE* pThisData			= this->m_pData->GetData();
	const TYPE* pDelimiterData	= Delimiter.m_pData->GetData();
	for(nCount1=(nStartIndex +1); nCount1<nThisSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nDelimiterSize; ++nCount2)
		{
			if(pThisData[nCount1] == pDelimiterData[nCount2])	// ��v����f�[�^�����������ꍇ
				break;
		}
		if(nCount2 < nDelimiterSize)
			break;
	}
	// �f�[�^�̒��o
	nResultSize	= nCount1 - nStartIndex -1;
	UArray.SetSize(nResultSize);
	TYPE* pResultData	= UArray.m_pData->GetData();
	for(nCount3=0; nCount3<nResultSize; ++nCount3)
		pResultData[nCount3]	= pThisData[nStartIndex +1 + nCount3];
	// �J�n�C���f�b�N�X�̍X�V
	if(nCount1 >= nThisSize)
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// ����I��
	return UArray;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Find(int& nStartIndex, ARG_TYPE DataFind) const
{	// <public> ����
	int		nThisSize;
	int		nCount1;

	// �z��̑傫���̎擾
	nThisSize	= this->m_pData->GetSize();

	// ����
	if(nStartIndex < -1 || nThisSize <= nStartIndex)
		return -1;	// �ُ�I��
	else if((nThisSize -1) == nStartIndex)
	{	// �f�[�^�̖����ɓ��B����ꍇ
		// �J�n�C���f�b�N�X�̍X�V
		nStartIndex		= -1;
		// ����I��
		return nStartIndex;
	}

	// ����
	const TYPE* pThisData	= this->m_pData->GetData();
	for(nCount1=(nStartIndex +1); nCount1<nThisSize; ++nCount1)
	{
		if(pThisData[nCount1] == DataFind)	// ��v����f�[�^�����������ꍇ
			break;
	}
	// �J�n�C���f�b�N�X�̍X�V
	if(nCount1 >= nThisSize)
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// ����I��
	return nStartIndex;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Find(int& nStartIndex, const CUArray<TYPE, ARG_TYPE>& DataStringFind) const
{	// <public> �f�[�^��Ɉ�v����f�[�^�̌���
	int		nThisSize, nDataStringSize;
	int		nCount1, nCount2;

	// �z��̑傫���̎擾
	nThisSize		= this->m_pData->GetSize();
	nDataStringSize	= DataStringFind.m_pData->GetSize();

	// ����
	if(nDataStringSize <= 0)
		return -1;	// �ُ�I��
	if(nStartIndex < -1 || (nThisSize - nDataStringSize +1) < nStartIndex)
		return -1;	// �ُ�I��
	else if((nThisSize - nDataStringSize) == nStartIndex)
	{	// �f�[�^�̖����ɓ��B����ꍇ
		// �J�n�C���f�b�N�X�̍X�V
		nStartIndex		= -1;
		// ����I��
		return nStartIndex;
	}

	// ����
	const TYPE* pThisData			= this->m_pData->GetData();
	const TYPE* pDataStringData	= DataStringFind.m_pData->GetData();
	for(nCount1=(nStartIndex +1); nCount1<(nThisSize - nDataStringSize +1); ++nCount1)
	{
		for(nCount2=0; nCount2<nDataStringSize; ++nCount2)
		{
			if(pThisData[nCount1 + nCount2] != pDataStringData[nCount2])	// ��v���Ȃ��f�[�^�����������ꍇ
				break;
		}
		if(nCount2 >= nDataStringSize)
			break;
	}
	// �J�n�C���f�b�N�X�̍X�V
	if(nCount1 >= (nThisSize - nDataStringSize +1) )
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// ����I��
	return nStartIndex;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::FindOneOf(int& nStartIndex, const CUArray<TYPE, ARG_TYPE>& DataSetFind) const
{	// <public> �f�[�^�Z�b�g�̂����ꂩ�Ɉ�v����f�[�^�̌���
	int		nThisSize, nDataSetSize;
	int		nCount1, nCount2;

	// �z��̑傫���̎擾
	nThisSize		= this->m_pData->GetSize();
	nDataSetSize	= DataSetFind.m_pData->GetSize();

	// ����
	if(nStartIndex < -1 || nThisSize <= nStartIndex)
		return -1;	// �ُ�I��
	else if((nThisSize -1) == nStartIndex)
	{	// �f�[�^�̖����ɓ��B����ꍇ
		// �J�n�C���f�b�N�X�̍X�V
		nStartIndex		= -1;
		// ����I��
		return nStartIndex;
	}
	if(nDataSetSize <= 0)
		return -1;	// �ُ�I��

	// ����
	const TYPE* pThisData		= this->m_pData->GetData();
	const TYPE* pDataSetData	= DataSetFind.m_pData->GetData();
	for(nCount1=(nStartIndex +1); nCount1<nThisSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nDataSetSize; ++nCount2)
		{
			if(pThisData[nCount1] == pDataSetData[nCount2])	// ��v����f�[�^�����������ꍇ
				break;
		}
		if(nCount2 < nDataSetSize)
			break;
	}
	// �J�n�C���f�b�N�X�̍X�V
	if(nCount1 >= nThisSize)
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// ����I��
	return nStartIndex;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::ReverseFind(int& nStartIndex, ARG_TYPE DataFind) const
{	// <public> �����i�t�����j
	int		nThisSize;
	int		nCount1;

	// �z��̑傫���̎擾
	nThisSize	= this->m_pData->GetSize();

	// ����
	if(nStartIndex < 0 || nThisSize < nStartIndex)
		return -1;	// �ُ�I��
	else if(0 == nStartIndex)
	{	// �f�[�^�̖����ɓ��B����ꍇ
		// �J�n�C���f�b�N�X�̍X�V
		nStartIndex		= -1;
		// ����I��
		return nStartIndex;
	}

	// ����
	const TYPE* pThisData	= this->m_pData->GetData();
	for(nCount1=(nStartIndex -1); nCount1>=0; --nCount1)
	{
		if(pThisData[nCount1] == DataFind)	// ��v����f�[�^�����������ꍇ
			break;
	}
	// �J�n�C���f�b�N�X�̍X�V
	if(nCount1 < 0)
		nStartIndex		= -1;
	else
		nStartIndex		= nCount1;

	// ����I��
	return nStartIndex;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::Replace(ARG_TYPE DataReplace, ARG_TYPE DataFind, int nStartIndex /* = 0 */, int nSize /* = -1 */)
{	// <public> �u��
	int		nCount1;

	// ����
	if(nStartIndex < 0 || this->m_pData->GetSize() <= nStartIndex)
		return 0;	// �ُ�I��
	if(nSize < -1)
		return 0;	// �ُ�I��
	else if(nSize == -1)
		nSize	= this->m_pData->GetSize();
	else
	{
		nSize	+= nStartIndex;
		if(nSize > this->m_pData->GetSize() )
			return 0;	// �ُ�I��
	}

	// ����
	TYPE* pThisData	= this->m_pData->GetData();
	for(nCount1=nStartIndex; nCount1<nSize; ++nCount1)
	{
		if(pThisData[nCount1] == DataFind)	// ��v����f�[�^�����������ꍇ
			pThisData[nCount1]	= DataReplace;
	}

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUArray<TYPE, ARG_TYPE>::ReplaceOneOf(ARG_TYPE DataReplace, const CUArray<TYPE, ARG_TYPE>& DataSetFind, int nStartIndex /* = 0 */, int nSize /* = -1 */)
{	// <public> �f�[�^�Z�b�g�̂����ꂩ�Ɉ�v����f�[�^�̒u��
	int		nDataSetSize;
	int		nCount1, nCount2;

	// �z��̑傫���̎擾
	nDataSetSize	= DataSetFind.m_pData->GetSize();

	// ����
	if(nDataSetSize <= 0)
		return 0;	// �ُ�I��
	if(nStartIndex < 0 || this->m_pData->GetSize() <= nStartIndex)
		return 0;	// �ُ�I��
	if(nSize < -1)
		return 0;	// �ُ�I��
	else if(nSize == -1)
		nSize	= this->m_pData->GetSize();
	else
	{
		nSize	+= nStartIndex;
		if(nSize > this->m_pData->GetSize() )
			return 0;	// �ُ�I��
	}

	// ����
	TYPE* pThisData			= this->m_pData->GetData();
	const TYPE* pDataSetData	= DataSetFind.m_pData->GetData();
	for(nCount1=nStartIndex; nCount1<nSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nDataSetSize; ++nCount2)
		{
			if(pThisData[nCount1] == pDataSetData[nCount2])
			{	// ��v����f�[�^�����������ꍇ
				pThisData[nCount1]	= DataReplace;
				break;
			}
		}
	}

	// ����I��
	return 1;
}

///////////////////////////////////////////////////////////////////////////////
// CUArray �g���N���X�쐬�x��

template <class TYPE, class ARG_TYPE>
inline const TYPE* CUArray<TYPE, ARG_TYPE>::GetData(void) const
{	// <public> �f�[�^�̔z��ւ̃|�C���^�̎擾
	return (const TYPE*)this->m_pData->GetData();
}

template <class TYPE, class ARG_TYPE>
inline TYPE* CUArray<TYPE, ARG_TYPE>::GetData(void)
{	// <public> �f�[�^�̔z��ւ̃|�C���^�̎擾
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
// ----- [ �f�[�^�����o ] -----
private:
	// �f�[�^
	TYPE*	m_pData;
	int		m_nSize;
	int		m_nMaxSize;
	// �Q�ƃJ�E���^
	int		m_nRef;

// ----- [ �֐������o : private ] -----
private:

// ----- [ �֐������o : protected ] -----
protected:
	// �\�z�E����
	CUArrayData();
	~CUArrayData();
	// ��{�f�[�^�A�N�Z�X
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
// CUArrayData ***** �����o�֐� *****
///////////////////////////////////////////////////////////////////////////////
// CUArrayData �\�z�E����

template <class TYPE, class ARG_TYPE>
CUArrayData<TYPE, ARG_TYPE>::CUArrayData()
{	// <protected> �\�z
	// ������
	this->m_pData		= NULL;
	this->m_nSize		= 0;
	this->m_nMaxSize	= 0;
	this->m_nRef		= 1;
}

template <class TYPE, class ARG_TYPE>
CUArrayData<TYPE, ARG_TYPE>::~CUArrayData()
{	// <protected> ����
	if(this->m_pData != NULL)
		delete [] this->m_pData;
}

///////////////////////////////////////////////////////////////////////////////
// CUArrayData ��{�f�[�^�A�N�Z�X

template <class TYPE, class ARG_TYPE>
inline const TYPE* CUArrayData<TYPE, ARG_TYPE>::GetData(void) const
{	// <protected> �f�[�^�ւ̃|�C���^�̎擾
	return (const TYPE*)this->m_pData;
}

template <class TYPE, class ARG_TYPE>
inline TYPE* CUArrayData<TYPE, ARG_TYPE>::GetData(void)
{	// <protected> �f�[�^�ւ̃|�C���^�̎擾
	return this->m_pData;
}

template <class TYPE, class ARG_TYPE>
inline int CUArrayData<TYPE, ARG_TYPE>::GetSize(void) const
{	// <protected> �T�C�Y�̎擾
	return this->m_nSize;
}

template <class TYPE, class ARG_TYPE>
int CUArrayData<TYPE, ARG_TYPE>::SetSize(int nSize)
{	// <protected> �T�C�Y�̐ݒ�
	if(nSize < 0)	// �T�C�Y�w�肪�s���ł���ꍇ
		return 0;	// �ُ�I��
	else if(nSize <= this->m_nMaxSize)
	{	// �����̃������̈�ő����ꍇ
		this->m_nSize	= nSize;
		return 1;	// ����I��
	}
	else
	{	// �V���ȃ������̈��K�v�Ƃ���ꍇ
		TYPE*	pData;
		int		nCount1;

		// �������u���b�N�̊��蓖��
		pData	= new TYPE[nSize];
		if(pData == NULL)
			return 0;	// �ُ�I��
		// ����
		for(nCount1=0; nCount1<this->m_nSize; ++nCount1)
			pData[nCount1]	= this->m_pData[nCount1];
		// �|�C���^�̏�������
		delete [] this->m_pData;
		this->m_pData	= pData;
		// �T�C�Y�̏�������
		this->m_nSize		= nSize;
		this->m_nMaxSize	= nSize;

		// ����I��
		return 1;
	}
}

template <class TYPE, class ARG_TYPE>
int CUArrayData<TYPE, ARG_TYPE>::FreeExtra(void)
{	// <protected> �]���ȃ������̉��
	if(this->m_nSize == 0 && this->m_pData != NULL)
	{	// �S�������̋���������K�v�ł���ꍇ
		delete [] this->m_pData;
		this->m_pData		= NULL;
		this->m_nSize		= 0;
		this->m_nMaxSize	= 0;
	}
	else if(this->m_nSize != this->m_nMaxSize)
	{	// �������̕����I����������K�v�ł���ꍇ
		TYPE*	pData;
		int		nCount1;

		// �������u���b�N�̊��蓖��
		pData	= new TYPE[this->m_nSize];
		if(pData == NULL)
			return 0;
		// ����
		for(nCount1=0; nCount1<this->m_nSize; ++nCount1)
			pData[nCount1]	= this->m_pData[nCount1];
		// �|�C���^�̏�������
		delete [] this->m_pData;
		this->m_pData	= pData;
		// �T�C�Y�̏�������
		this->m_nMaxSize	= this->m_nSize;
	}

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
inline int CUArrayData<TYPE, ARG_TYPE>::GetRef(void) const
{	// <protected> �Q�ƃJ�E���^�̎擾
	return this->m_nRef;
}

template <class TYPE, class ARG_TYPE>
inline int CUArrayData<TYPE, ARG_TYPE>::IncRef(int nCount /* = 1 */)
{	// <protected> �Q�ƃJ�E���^�̑���
	return (this->m_nRef += nCount);
}

template <class TYPE, class ARG_TYPE>
inline int CUArrayData<TYPE, ARG_TYPE>::DecRef(int nCount /* = 1 */)
{	// <protected> �Q�ƃJ�E���^�̌���
	return (this->m_nRef -= nCount);
}

///////////////////////////////////////////////////////////////////////////////


#endif	// __UARRAY_H__

// ----------------------------------------------------------------------------
// End of UARRAY.H
// ----------------------------------------------------------------------------
