#pragma once

class TNumber {
private:
    double num;
public:
    TNumber(double n);
    double getNum();
    virtual int findNum() = 0;
    virtual void init(int n) = 0;
    static void sumNum(TNumber* numberArray, int size);
};

class TIntNumber : public TNumber {
public:
    TIntNumber();
    TIntNumber(int n);
    void init(int m) override;
    int findNum() override;
};

class TRealNumber : public TNumber {
public:
    TRealNumber();
    TRealNumber(double n);
    void init(int n) override;
    int findNum() override;
};
