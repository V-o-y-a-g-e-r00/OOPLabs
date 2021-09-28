//queue.inl inline ���� ��� ���������� ������� �������� ������� Queue � Node

//=============Node====
template <typename T>
Node<T>::Node(T NNodeVal):NodeVal(NNodeVal), Next(nullptr)
{

}

//=============Queue====
/*  ������� � ����� private*/
template <typename T>
Node<T>* Queue<T>::SearchPenultPointer()
{
    Node<T>* Penult=First; //�������������
    while((Penult->Next)->Next!=nullptr)
    {
        Penult=Penult->Next;
    }
    return Penult;
}
/*  ������������ � ����������*/
template <typename T>
Queue<T>::Queue():First(nullptr), Last(nullptr)
{

}

template <typename T>
Queue<T>::Queue(const Queue& Q2) //��� ������������ � ��. ��������� �� ������� ��������� ����������� �������.
{
    Node<T> *Slider, *Swap; //Slider ����� �� ������� ����������� �������. Swap ��� ���������� �������� ��������� �� ����� ����.
    if(Q2.IsEmpty())
    {
        First=nullptr;
        Last=nullptr;
    }
    else
    {
        First=new Node<T>(Q2.First->NodeVal);
        First->Next=Q2.First->Next;
        Last=First; //��� ������, ��������� �� ��������� ���� ��������� �� ��� �� ����, ��� � ��������� �� ������ ����.

        Slider=Q2.First->Next;
        while(Slider!=nullptr)
        {
            Swap=Last;
            Last=new Node<T>(Slider->NodeVal);
            Swap->Next=Last;
            Slider=Slider->Next;
        }
        Last->Next=nullptr; //��� ���� �� ������������� �������� Last->Next � �������� ��������, � ������ � �����������, ������� �� ��������� ������� ��� ����� �����.
    }
}

template <typename T>
Queue<T>::~Queue()
{
    std::cout << "destructor" <<std::endl;
    if(IsEmpty()) return;
    Node<T>* Temporary;
    while(First!=nullptr)
    {
        Temporary=First->Next;
        delete First;
        First=Temporary;
    }
    Last=nullptr;
}

/*  ������ Push Pop GetFront IsEmpty*/
template <typename T>
bool Queue<T>::IsEmpty() const //����������� ����� ��� ������ ������������ �����������.
{
    return First==nullptr;
}

template <typename T>
    void Queue<T>::Push(T NNodeVal)
    {
        Node<T>* Penult; //�������������
        if(First==nullptr)
        {
            First=new Node<T>(NNodeVal);
            Last=First;
        }
        else
        {
            Penult=Last;
            Last=new Node<T>(NNodeVal);
            Penult->Next=Last;
        }
    }
    template <typename T>
    void Queue<T>::Pop()
    {
        Node<T>* Penult; //�������������
        if(First==nullptr)
        {
            std::cout<<"Pop: queue already empty!"<<std::endl;
            throw "Exception: Pop: queue already empty!";
            return;
        }
        if(First==Last)
        {
            delete First;
            First=nullptr;
            Last=nullptr;
        }
        else
        {
            Penult=SearchPenultPointer();
            delete Last;
            Last=Penult;
            Last->Next=nullptr;
        }
    }
    template <typename T>
    T Queue<T>::GetFront()
    {
        if(!IsEmpty())
            return Last->NodeVal;
        else throw "Exception: GetFront: Cannot get element from empty queue!";
    }
