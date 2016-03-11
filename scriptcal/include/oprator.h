// ----------------------------------------------------
// ----------------------运算类------------------------
// ----------------------------------------------------

template <typename T>
class COperation
{
public:
    virtual T GetResult();
    virtual void SetPara();
    virtual vector<T> GetPara();
private:
    vector<T> m_para;
};

template <typename T>
class COperationAdd:public COperation
{
// ...
};

template <typename T>
class COperationSub:public COperation
{};

// ...

// 运算工厂
template <typename T>
class COperationFactory
{
public:
    static COperation<T> createOperation(string operate){
        // ...
        return new CoperationAdd();
    }
}





