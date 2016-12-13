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
// ----- [ �f�[�^�����o ] -----
protected:
	CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>*	m_pData;

// ----- [ �֐������o : protected ] -----
protected:
	// ��{�����葀��i�����֐��j
	int		_GetSizeRow(void) const;
	int		_GetSizeCol(void) const;
	int		_SetSize(int, int);
	int		_RemoveAt(int, int, int = 1, int = 1);
	int		_RemoveAll(void);

// ----- [ �֐������o : public ] -----
public:
	// �\�z�E����
	CUMatrix();
	CUMatrix(const CUMatrix<TYPE, ARG_TYPE>&);
	~CUMatrix();
	// ��{����������
	int		GetSize(int&, int&) const;
	int		GetSizeRow(void) const;
	int		GetSizeCol(void) const;
	int		SetSize(int, int);
	int		RemoveAt(int, int, int = 1, int = 1);
	int		RemoveAll(void);
	// �f�[�^����
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
	// ��r�E���o�E�����E�u��
	int		Compare(const CUMatrix<TYPE, ARG_TYPE>&) const;
	int		operator ==(const CUMatrix<TYPE, ARG_TYPE>&) const;
	int		operator !=(const CUMatrix<TYPE, ARG_TYPE>&) const;

	// ���̑����Z
     CUMatrix<TYPE, ARG_TYPE> Inverse(void);            //�t�s�񉉎Z

	// �g���N���X�쐬�x���i�� ���ۂ̋@�\�́A�ʃN���X�ŃT�|�[�g�B���j
	const CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>*	GetData(void) const;
	CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>*		GetData(void);
};

///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// CUMatrix ***** �����o�֐� *****
///////////////////////////////////////////////////////////////////////////////
// CUMatrix �\�z�E����

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE>::CUMatrix()
{	// <public> �\�z
	// �\�z
	this->m_pData	= new CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE>::CUMatrix(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> �\�z
	// �\�z
	this->m_pData	= new CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>;
	// ����
	this->Copy(UMatrix);
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE>::~CUMatrix()
{	// <public> ����
	// �j��
	delete this->m_pData;
}

///////////////////////////////////////////////////////////////////////////////
// CUMatrix ��{����������

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::_GetSizeRow(void) const
{	// <protected> �s���̎擾�i�����֐��j
	return this->m_pData->GetSize();
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::_GetSizeCol(void) const
{	// <protected> �񐔂̎擾�i�����֐��j
	if(this->m_pData->GetSize() == 0)
		return 0;
	else
		return this->m_pData->GetAt(0).GetSize();
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::_SetSize(int nRowSize, int nColSize)
{	// <protected> �s��̑傫���̐ݒ�i�����֐��j
	int		nCount1;

	// ����
	if(nRowSize < 0 || nColSize < 0)
		return 0;	// �ُ�I��

	// �s���̐ݒ�
	this->m_pData->SetSize(nRowSize);
	// �񐔂̐ݒ�
	for(nCount1=0; nCount1<this->m_pData->GetSize(); ++nCount1)
		this->m_pData->ElementAt(nCount1).SetSize(nColSize);

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::_RemoveAt(int nRowIndex, int nColIndex, int nRowCount /* = 1 */, int nColCount /* = 1 */)
{	// <protected> �w��s�E�w���̍폜�i�����֐��j
	// �s�̍폜
	if(nRowIndex >= 0 && nRowCount > 0)
	{	// �s���폜����ꍇ
		// ����
		if(this->m_pData->GetSize() < (nRowIndex + nRowCount) )	// ���݂��Ȃ��s���폜���悤�Ƃ����ꍇ
			return 0;	// �ُ�I��
		// �폜
		this->m_pData->RemoveAt(nRowIndex, nRowCount);
	}

	// ��̍폜
	if(nColIndex >= 0 && nColCount > 0 && this->m_pData->GetSize() > 0)
	{	// ����폜����ꍇ�i��ł���ꍇ�������j
		// ����
		if(this->m_pData->GetAt(0).GetSize() < (nColIndex + nColCount) )	// ���݂��Ȃ�����폜���悤�Ƃ����ꍇ
			return 0;	// �ُ�I��
		// �폜
		if(nColIndex == 0 && this->m_pData->GetAt(0).GetSize() == nColCount)	// �S�폜�ł���ꍇ
			this->m_pData->RemoveAll();
		else
		{	// �ʏ�̍폜�ł���ꍇ
			int		nCount1;

			for(nCount1=0; nCount1<this->m_pData->GetSize(); ++nCount1)
				this->m_pData->ElementAt(nCount1).RemoveAt(nColIndex, nColCount);
		}
	}

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::_RemoveAll(void)
{	// <protected> �S�폜�i�����֐��j
	return this->m_pData->RemoveAll();
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::GetSize(int& nRowSize, int& nColSize) const
{	// <public> �s��̑傫���̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();
	return 1;
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::GetSizeRow(void) const
{	// <public> �s���̎擾
	return this->_GetSizeRow();
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::GetSizeCol(void) const
{	// <public> �񐔂̎擾
	return this->_GetSizeCol();
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::SetSize(int nRowSize, int nColSize)
{	// <public> �s��̑傫���̐ݒ�
	return this->_SetSize(nRowSize, nColSize);
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::RemoveAt(int nRowIndex, int nColIndex, int nRowCount /* = 1 */, int nColCount /* = 1 */)
{	// <public> �w��s�E�w���̍폜
	return this->_RemoveAt(nRowIndex, nColIndex, nRowCount, nColCount);
}

template <class TYPE, class ARG_TYPE>
inline int CUMatrix<TYPE, ARG_TYPE>::RemoveAll(void)
{	// <public> �S�폜
	return this->_RemoveAll();
}

///////////////////////////////////////////////////////////////////////////////
// CUMatrix �f�[�^����

template <class TYPE, class ARG_TYPE>
TYPE CUMatrix<TYPE, ARG_TYPE>::GetAt(int nRowIndex, int nColIndex) const
{	// <public> �v�f�̎擾
	return this->m_pData->GetAt(nRowIndex).GetAt(nColIndex);
}

template <class TYPE, class ARG_TYPE>
TYPE& CUMatrix<TYPE, ARG_TYPE>::ElementAt(int nRowIndex, int nColIndex)
{	// <public> �v�f�̎擾
	return this->m_pData->ElementAt(nRowIndex).ElementAt(nColIndex);
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::Extract(int nRowIndex, int nRowSize, int nColIndex, int nColSize) const
{	// <public> �����s��̎擾
	CUMatrix<TYPE, ARG_TYPE>	Matrix;
	int		nCount1, nCount2;

	// ����
	if(nRowIndex < 0)
		return Matrix;	// �ُ�I��
	if(nColIndex < 0)
		return Matrix;	// �ُ�I��

	// �f�t�H���g�̍s���A�񐔂̐ݒ�
	if(nRowSize <= 0)
		nRowSize	= this->_GetSizeRow() - nRowIndex;
	if(nColSize <= 0)
		nColSize	= this->_GetSizeCol() - nColIndex;

	// ����
	if(nRowSize <= 0 || this->_GetSizeRow() < (nRowIndex + nRowSize) )	// ���݂��Ȃ��s���擾���悤�Ƃ����ꍇ
		return Matrix;	// �ُ�I��
	if(nColSize <= 0 || this->_GetSizeCol() < (nColIndex + nColSize) )	// ���݂��Ȃ�����擾���悤�Ƃ����ꍇ
		return Matrix;	// �ُ�I��

	// �s��̑傫���̐ݒ�
	Matrix._SetSize(nRowSize, nColSize);
	// ����
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			Matrix.m_pData->ElementAt(nCount1).SetAt(nCount2, this->m_pData->GetAt(nRowIndex + nCount1).GetAt(nColIndex + nCount2) );
	}

	// ����I��
	return Matrix;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAt(int nRowIndex, int nColIndex, ARG_TYPE Element)
{	// <public> �v�f�̐ݒ�
	// ����
	if(nRowIndex < 0 || this->_GetSizeRow() <= nRowIndex)
		return 0;	// �ُ�I��
	if(nColIndex < 0 || this->_GetSizeCol() <= nColIndex)
		return 0;	// �ُ�I��

	// �v�f�̐ݒ�
	this->m_pData->ElementAt(nRowIndex).ElementAt(nColIndex)	= Element;
	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAtGrow(int nRowIndex, int nColIndex, ARG_TYPE Element)
{	// <public> �v�f�̐ݒ�i�z�񎩓��g���j
	int		nNewRowSize, nNewColSize;
	int		nCount1;

	// ����
	if(nRowIndex < 0)
		return 0;	// �ُ�I��
	if(nColIndex < 0)
		return 0;	// �ُ�I��

	// �s���̌���
	nNewRowSize	= this->_GetSizeRow();
	if(nNewRowSize <= nRowIndex)	// �s�����g������K�v������ꍇ
		nNewRowSize	= nRowIndex +1;
	// �񐔂̌���
	nNewColSize	= this->_GetSizeCol();
	if(nNewColSize <= nColIndex)	// �񐔂��g������K�v������ꍇ
		nNewColSize	= nColIndex +1;
	// �s��̑傫���̐ݒ�
	this->_SetSize(nNewRowSize, nNewColSize);

	// �v�f�̐ݒ�
	this->m_pData->ElementAt(nRowIndex).ElementAt(nColIndex)	= Element;
	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAt(int nRowIndex, int nColIndex, const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> �v�f�̐ݒ�
	int		nCount1, nCount2;

	// ����
	if(nRowIndex < 0 || this->_GetSizeRow() < (nRowIndex + UMatrix.GetSizeRow() ) )
		return 0;	// �ُ�I��
	if(nColIndex < 0 || this->_GetSizeCol() < (nColIndex + UMatrix.GetSizeCol() ) )
		return 0;	// �ُ�I��

	// �v�f�̐ݒ�
	for(nCount1=0; nCount1<UMatrix._GetSizeRow(); ++nCount1)
	{
		for(nCount2=0; nCount2<UMatrix._GetSizeCol(); ++nCount2)
			this->m_pData->ElementAt(nRowIndex + nCount1).ElementAt(nColIndex + nCount2)	= UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAtGrow(int nRowIndex, int nColIndex, const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> �v�f�̐ݒ�i�z�񎩓��g���j
	int		nNewRowSize, nNewColSize;
	int		nCount1, nCount2;

	// ����
	if(nRowIndex < 0)
		return 0;	// �ُ�I��
	if(nColIndex < 0)
		return 0;	// �ُ�I��

	// �s���̌���
	nNewRowSize	= this->_GetSizeRow();
	if(nNewRowSize < (nRowIndex + UMatrix._GetSizeRow() ) )	// �s�����g������K�v������ꍇ
		nNewRowSize	= nRowIndex + UMatrix._GetSizeRow();
	// �񐔂̌���
	nNewColSize	= this->_GetSizeCol();
	if(nNewColSize < (nColIndex + UMatrix._GetSizeCol() ) )	// �񐔂��g������K�v������ꍇ
		nNewColSize	= nColIndex + UMatrix._GetSizeCol();
	// �s��̑傫���̐ݒ�
	this->_SetSize(nNewRowSize, nNewColSize);

	// �v�f�̐ݒ�
	for(nCount1=0; nCount1<UMatrix._GetSizeRow(); ++nCount1)
	{
		for(nCount2=0; nCount2<UMatrix._GetSizeCol(); ++nCount2)
			this->m_pData->ElementAt(nRowIndex + nCount1).ElementAt(nColIndex + nCount2)	= UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAt(int nRowIndex, int nColIndex, const TYPE* pElement, int nRowSize /* = -1 */, int nColSize /* = -1 */)
{	// <public> �v�f�̈ꊇ�ݒ�
	int		nStartIndex;
	int		nCount1, nCount2;

	// �s���A�񐔂̎擾
	if(nRowSize == -1 && nColSize == -1)
	{	// �s���A�񐔂������I�Ɏw�肳��Ă��Ȃ��ꍇ�i�� �v�f�z��̐擪 2 �o�C�g�ɍs���A�񐔂������Ă���A�����čs��v�f�������Ă���B�j
		// �s���A�񐔂̎擾
		nRowSize	= (int)pElement[0];
		nColSize	= (int)pElement[1];
		// �s��v�f�J�n�C���f�b�N�X�̐ݒ�
		nStartIndex	= 2;
	}
	else	// �s���A�񐔂������I�Ɏw�肳��Ă���ꍇ�i�� �v�f�z��ɂ͍s��v�f�݂̂������Ă���B�j
		nStartIndex	= 0;	// �s��v�f�J�n�C���f�b�N�X�̐ݒ�

	// ����
	if(nRowIndex < 0 || this->_GetSizeRow() < (nRowIndex + nRowSize) )
		return 0;	// �ُ�I��
	if(nColIndex < 0 || this->_GetSizeCol() < (nColIndex + nColSize) )
		return 0;	// �ُ�I��

	// �v�f�̏�������
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nRowIndex + nCount1).ElementAt(nColIndex + nCount2)	= pElement[nStartIndex + nCount1*nColSize + nCount2];
	}

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAtGrow(int nRowIndex, int nColIndex, const TYPE* pElement, int nRowSize /* = -1 */, int nColSize /* = -1 */)
{	// <public> �v�f�̈ꊇ�ݒ�i�z�񎩓��g���j
	int		nNewRowSize, nNewColSize;
	int		nStartIndex;
	int		nCount1, nCount2;

	// �s���A�񐔂̎擾
	if(nRowSize == -1 && nColSize == -1)
	{	// �s���A�񐔂������I�Ɏw�肳��Ă��Ȃ��ꍇ�i�� �v�f�z��̐擪 2 �o�C�g�ɍs���A�񐔂������Ă���A�����čs��v�f�������Ă���B�j
		// �s���A�񐔂̎擾
		nRowSize	= (int)pElement[0];
		nColSize	= (int)pElement[1];
		// �s��v�f�J�n�C���f�b�N�X�̐ݒ�
		nStartIndex	= 2;
	}
	else	// �s���A�񐔂������I�Ɏw�肳��Ă���ꍇ�i�� �v�f�z��ɂ͍s��v�f�݂̂������Ă���B�j
		nStartIndex	= 0;	// �s��v�f�J�n�C���f�b�N�X�̐ݒ�

	// ����
	if(nRowIndex < 0)
		return 0;	// �ُ�I��
	if(nColIndex < 0)
		return 0;	// �ُ�I��

	// �s���̌���
	nNewRowSize	= this->_GetSizeRow();
	if(nNewRowSize < (nRowIndex + nRowSize) )	// �s�����g������K�v������ꍇ
		nNewRowSize	= nRowIndex + nRowSize;
	// �񐔂̌���
	nNewColSize	= this->_GetSizeCol();
	if(nNewColSize < (nColIndex + nColSize) )	// �񐔂��g������K�v������ꍇ
		nNewColSize	= nColIndex + nColSize;
	// �s��̑傫���̐ݒ�
	this->_SetSize(nNewRowSize, nNewColSize);

	// �v�f�̏�������
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nRowIndex + nCount1).ElementAt(nColIndex + nCount2)	= pElement[nStartIndex + nCount1*nColSize + nCount2];
	}

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::SetAllZero(void)
{	// <public> ���ׂĂ̗v�f�ւ� 0 �̏�������
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// �����ƍs���E�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// ��������
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nCount1).ElementAt(nCount2)	= 0;
	}

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::Copy(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> �s��̕���
	// �f�[�^�̕���
	return this->m_pData->Copy(*UMatrix.m_pData);
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator =(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> �s��̕���
	// �f�[�^�̕���
	this->m_pData->Copy(*UMatrix.m_pData);
	// ����I��
	return (const CUMatrix<TYPE, ARG_TYPE>&)*this;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::operator +(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> ���Z
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// �s���A�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();
	// ����
	if(nRowSize != UMatrix._GetSizeRow() )	// �s�����قȂ�ꍇ
		return UMatrixResult;	// �ُ�I��
	if(nColSize != UMatrix._GetSizeCol() )	// �񐔂��قȂ�ꍇ
		return UMatrixResult;	// �ُ�I��

	// �s��̑傫���̐ݒ�
	UMatrixResult._SetSize(nRowSize, nColSize);
	// ���Z
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	= this->m_pData->GetAt(nCount1).GetAt(nCount2) + UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// ����I��
	return UMatrixResult;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::operator -(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> ���Z
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// �s���A�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();
	// ����
	if(nRowSize != UMatrix._GetSizeRow() )	// �s�����قȂ�ꍇ
		return UMatrixResult;	// �ُ�I��
	if(nColSize != UMatrix._GetSizeCol() )	// �񐔂��قȂ�ꍇ
		return UMatrixResult;	// �ُ�I��

	// �s��̑傫���̐ݒ�
	UMatrixResult._SetSize(nRowSize, nColSize);
	// ���Z
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	= this->m_pData->GetAt(nCount1).GetAt(nCount2) - UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// ����I��
	return UMatrixResult;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::operator *(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> ��Z
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize, nItrSize;
	int		nCount1, nCount2, nCount3;

	// �s���A�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= UMatrix._GetSizeCol();
	nItrSize	= this->_GetSizeCol();
	// ����
	if(nItrSize != UMatrix._GetSizeRow() )	// ���ӂ̗񐔂ƉE�ӂ̍s�����قȂ�ꍇ
		return UMatrixResult;	// �ُ�I��

	// �s��̑傫���̐ݒ�
	UMatrixResult._SetSize(nRowSize, nColSize);
	// ���Z
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
		{
			// �����l�̑��
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	= 0;

			for(nCount3=0; nCount3<nItrSize; ++nCount3)
				UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	+= this->m_pData->GetAt(nCount1).GetAt(nCount3) * UMatrix.m_pData->GetAt(nCount3).GetAt(nCount2);
		}
	}

	// ����I��
	return UMatrixResult;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::operator *(ARG_TYPE Number) const
{	// <public> ��Z
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// �s���A�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// ���Z���ʍs��̐ݒ�
	UMatrixResult.Copy(*this);
	// ���Z
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	*= Number;
	}

	// ����I��
	return UMatrixResult;
}

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::operator /(ARG_TYPE Number) const
{	// <public> ���Z
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// �s���A�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// ���Z���ʍs��̐ݒ�
	UMatrixResult.Copy(*this);
	// ���Z
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	/= Number;
	}

	// ����I��
	return UMatrixResult;
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator +=(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> ���Z���
	int			nRowSize, nColSize;
	int			nCount1, nCount2;

	// �s���A�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();
	// ����
/*	if(nRowSize != UMatrix._GetSizeRow() )	// �s�����قȂ�ꍇ
		return UMatrixResult;	// �ُ�I��
	if(nColSize != UMatrix._GetSizeCol() )	// �񐔂��قȂ�ꍇ
		return UMatrixResult;	// �ُ�I��
*/
	// ���Z
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nCount1).ElementAt(nCount2) += UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// ����I��
	return *this;
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator -=(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> ���Z���
	int			nRowSize, nColSize;
	int			nCount1, nCount2;

	// �s���A�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();
	// ����
/*	if(nRowSize != UMatrix._GetSizeRow() )	// �s�����قȂ�ꍇ				20160213 �R�����g�A�E�g
		return UMatrixResult;	// �ُ�I��
	if(nColSize != UMatrix._GetSizeCol() )	// �񐔂��قȂ�ꍇ
		return UMatrixResult;	// �ُ�I��
*/
	// ���Z
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nCount1).ElementAt(nCount2) -= UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2);
	}

	// ����I��
	return *this;
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator *=(const CUMatrix<TYPE, ARG_TYPE>& UMatrix)
{	// <public> ��Z���
	CUMatrix<TYPE, ARG_TYPE>	UMatrixResult;
	int		nRowSize, nColSize, nItrSize;
	int		nCount1, nCount2, nCount3;

	// �s���A�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= UMatrix._GetSizeCol();
	nItrSize	= this->_GetSizeCol();
	// ����
	if(nItrSize != UMatrix._GetSizeRow() )	// ���ӂ̗񐔂ƉE�ӂ̍s�����قȂ�ꍇ
		return UMatrixResult;	// �ُ�I��

	// �s��̑傫���̐ݒ�
	UMatrixResult._SetSize(nRowSize, nColSize);
	// ���Z
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
		{
			// �����l�̑��
			UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	= 0;

			for(nCount3=0; nCount3<nItrSize; ++nCount3)
				UMatrixResult.m_pData->ElementAt(nCount1).ElementAt(nCount2)	+= this->m_pData->GetAt(nCount1).GetAt(nCount3) * UMatrix.m_pData->GetAt(nCount3).GetAt(nCount2);
		}
	}

	// ����
	this->m_pData->Copy(*UMatrixResult.m_pData);
	// ����I��
	return *this;
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator *=(ARG_TYPE Number)
{	// <public> ��Z���
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// �s���E�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// ���Z
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nCount1).ElementAt(nCount2)	*= Number;
	}

	// ����I��
	return *this;
}

template <class TYPE, class ARG_TYPE>
const CUMatrix<TYPE, ARG_TYPE>& CUMatrix<TYPE, ARG_TYPE>::operator /=(ARG_TYPE Number)
{	// <public> ���Z���
	int		nRowSize, nColSize;
	int		nCount1, nCount2;

	// �s���E�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// ���Z
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
			this->m_pData->ElementAt(nCount1).ElementAt(nCount2)	/= Number;
	}

	// ����I��
	return *this;
}

///////////////////////////////////////////////////////////////////////////////
// CUMatrix ���̑����Z

template <class TYPE, class ARG_TYPE>
CUMatrix<TYPE, ARG_TYPE> CUMatrix<TYPE, ARG_TYPE>::Inverse(void) 
{  //�t�s��̉��Z

   CUMatrix<double, const double&> IMatrix;
   CUMatrix<double, const double&> IC;


   double P,Temp1,Temp2, Temp3;
   int Row,Col;
   int i,j,k;

   Row = this->_GetSizeRow();
   Col = this->_GetSizeCol();

   IC.SetSize(Row,Col);
   IC.SetAllZero();


   if(Row != Col)           //�s�񂪐����łȂ��ꍇ
	   return IC;              //�ُ�I���@

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
// CUMatrix ��r�E���o�E�����E�u��

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::Compare(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> ��r
	int			nRowSize, nColSize;
	int			nCount1, nCount2;

	// �s���E�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// �s���E�񐔂̔�r
	if(nRowSize != UMatrix._GetSizeRow() )	// �s�����قȂ�ꍇ
		return 1;
	if(nColSize != UMatrix._GetSizeCol() )	// �񐔂��قȂ�ꍇ
		return 1;
	// �v�f�̔�r
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
		{
			if(this->m_pData->GetAt(nCount1).GetAt(nCount2) != UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2) )	// �v�f���قȂ�ꍇ
				return 1;
		}
	}

	// ����I��
	return 0;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::operator ==(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> ��r
	int			nRowSize, nColSize;
	int			nCount1, nCount2;

	// �s���E�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// �s���E�񐔂̔�r
	if(nRowSize != UMatrix._GetSizeRow() )	// �s�����قȂ�ꍇ
		return 0;
	if(nColSize != UMatrix._GetSizeCol() )	// �񐔂��قȂ�ꍇ
		return 0;
	// �v�f�̔�r
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
		{
			if(this->m_pData->GetAt(nCount1).GetAt(nCount2) != UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2) )	// �v�f���قȂ�ꍇ
				return 0;
		}
	}

	// ����I��
	return 1;
}

template <class TYPE, class ARG_TYPE>
int CUMatrix<TYPE, ARG_TYPE>::operator !=(const CUMatrix<TYPE, ARG_TYPE>& UMatrix) const
{	// <public> ��r
	int			nRowSize, nColSize;
	int			nCount1, nCount2;

	// �s���E�񐔂̎擾
	nRowSize	= this->_GetSizeRow();
	nColSize	= this->_GetSizeCol();

	// �s���E�񐔂̔�r
	if(nRowSize != UMatrix._GetSizeRow() )	// �s�����قȂ�ꍇ
		return 1;
	if(nColSize != UMatrix._GetSizeCol() )	// �񐔂��قȂ�ꍇ
		return 1;
	// �v�f�̔�r
	for(nCount1=0; nCount1<nRowSize; ++nCount1)
	{
		for(nCount2=0; nCount2<nColSize; ++nCount2)
		{
			if(this->m_pData->GetAt(nCount1).GetAt(nCount2) != UMatrix.m_pData->GetAt(nCount1).GetAt(nCount2) )	// �v�f���قȂ�ꍇ
				return 1;
		}
	}

	// ����I��
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// CUMatrix �g���N���X�쐬�x��

template <class TYPE, class ARG_TYPE>
inline const CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>* CUMatrix<TYPE, ARG_TYPE>::GetData(void) const
{	// <public> �f�[�^�ւ̃|�C���^�̎擾
	return this->m_pData;
}

template <class TYPE, class ARG_TYPE>
inline CUArray<CUArray<TYPE, ARG_TYPE>, const CUArray<TYPE, ARG_TYPE>&>* CUMatrix<TYPE, ARG_TYPE>::GetData(void)
{	// <public> �f�[�^�̔z��ւ̃|�C���^�̎擾
	return this->m_pData;
}

///////////////////////////////////////////////////////////////////////////////


#endif	// __UMATRIX_H__

// ----------------------------------------------------------------------------
// End of UMATRIX.H
// ----------------------------------------------------------------------------
