#ifndef CMATRIX
#define CMATRIX

class CMatrix {
public:
	float mM[4][4];
	CMatrix();
	CMatrix Identity() ;
	CMatrix RotateY(float degree);
	const CMatrix RotateX(float degree);
	CMatrix Scale(float x, float y, float z);
	CMatrix Translate(float x, float y, float z);
	CMatrix Multi(const CMatrix &m);
	CMatrix operator*(const CMatrix &m);

};

#endif
