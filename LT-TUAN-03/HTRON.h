#pragma once
#ifndef _HTRON
#include "DIEM.h"

class HTRON
{
private:
	DIEM O;
	double R;

public:
	HTRON();
	HTRON(const DIEM& O, double R);
    void SetO(const DIEM& O);  
    DIEM GetO() const;        
    void SetR(double R);       
    double GetR() const;        
    void Nhap();               
    void Xuat() const;          
    void DiChuyen(double dx, double dy); 
    double TinhChuVi() const; 
    double TinhDienTich() const; 
    bool KiemTraHopLe() const;
};

#endif;
