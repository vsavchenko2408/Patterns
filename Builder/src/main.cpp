#include <iostream>

class Data
{
    int m_idata;
    float m_fdata;
    bool m_bdata;
    public:
    Data() : m_idata(0), m_fdata(0.0), m_bdata(false){}
    Data(int idata, float fdata, bool bdata ) : m_idata(idata), m_fdata(fdata), m_bdata(bdata){}
    int get_integerdata()
    {
        return m_idata;
    }
    float get_floatdata()
    {
        return m_fdata;
    }
    bool get_booldata()
    {
        return m_bdata;
    }
    void set_int(int idata)
    {
        m_idata = idata;
    }
        void set_float(float fdata)
    {
        m_fdata = fdata;
    }
        void set_bool(bool bdata)
    {
        m_bdata = bdata;
    }
    void info()
    {
        std::cout << "___________________________________________________________________________" << std::endl;
        std::cout << "Integer data: " << m_idata << std::endl;
        std::cout << "Float data: " << m_fdata << std::endl;
        std::cout << "Bool data: " << m_bdata << std::endl;
        std::cout << "___________________________________________________________________________" << std::endl;
    }
};

class DataBuilder
{
    Data data;
    public:
    DataBuilder& setInt(int value)
    {
        data.set_int(value);
        return *this;
    }
    DataBuilder& setFloat(float value)
    {
        data.set_float(value);
        return *this;
    }
    DataBuilder& setBool(bool value)
    {
        data.set_bool(value);
        return *this;
    }
    Data build()
    {
        return data;
    }
};
int main()
{
    DataBuilder database;
    Data data1 = database
        .setInt(15)
        .setFloat(25.7)
        .setBool(true)
        .build();
    data1.info();
    Data data2 = database
        .setInt(10)
        .setFloat(14.3)
        .setBool(true)
        .build();
        data2.info();

}