#include <Eigen/Core>
#include <Eigen/Geometry>

inline Eigen::MatrixXd SetAtGrow(int nRowIndex, int nColIndex, Eigen::MatrixXd Matrix1, Eigen::MatrixXd Matrix2)
{
	int nCount1, nCount2;

	// 検査
	if(nRowIndex < 0)
		return Matrix1;	// 異常終了
	if(nColIndex < 0)
		return Matrix1;	// 異常終了

	// 行数の検査
	if(Matrix1.rows() < (nRowIndex + Matrix2.rows() ) )	// 行数を拡張する必要がある場合
		Matrix1.resize(nRowIndex + Matrix2.rows(), Eigen::NoChange);		
	// 列数の検査
	if(Matrix1.cols() < (nColIndex + Matrix2.cols() ) )	// 列数を拡張する必要がある場合
		Matrix1.resize(Eigen::NoChange, nColIndex + Matrix2.cols());

	// 要素の設定
	for(nCount1 = 0; nCount1 < Matrix2.rows(); ++nCount1)
	{
		for(nCount2 = 0; nCount2 < Matrix2.cols(); ++nCount2)
			Matrix1(nRowIndex + nCount1, nColIndex + nCount2)	= Matrix2(nCount1, nCount2);
	}

	// 正常終了
	return Matrix1;
}


inline Eigen::MatrixXd Extract(int nRowIndex, int nRowSize, int nColIndex, int nColSize, Eigen::MatrixXd Matrix)
{
	// <public> 部分行列の取得
	Eigen::MatrixXd nMatrix;

	// 検査
	if(nRowIndex < 0)
		return Matrix;	// 異常終了
	if(nColIndex < 0)
		return Matrix;	// 異常終了

	// デフォルトの行数、列数の設定
	if(nRowSize <= 0)
		nRowSize	= Matrix.rows() - nRowIndex;
	if(nColSize <= 0)
		nColSize	= Matrix.cols() - nColIndex;

	// 検査
	if(nRowSize <= 0 || Matrix.rows() < (nRowIndex + nRowSize) )	// 存在しない行を取得しようとした場合
		return Matrix;	// 異常終了
	if(nColSize <= 0 || Matrix.cols() < (nColIndex + nColSize) )	// 存在しない列を取得しようとした場合
		return Matrix;	// 異常終了

	// 行列の大きさの設定
	nMatrix = Matrix.block(nRowIndex, nColIndex,Matrix.rows() - nRowIndex, Matrix.cols() - nColIndex);
	

	// 正常終了
	return nMatrix;
}
