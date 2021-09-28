//queue.inl inline файл для реализации методов шаблонов классов Queue и Node

//=============Node====
template <typename T>
Node<T>::Node(T NNodeVal):NodeVal(NNodeVal), Next(nullptr)
{

}

//=============Queue====
/*  функция в блоке private*/
template <typename T>
Node<T>* Queue<T>::SearchPenultPointer()
{
    Node<T>* Penult=First; //предпоследний
    while((Penult->Next)->Next!=nullptr)
    {
        Penult=Penult->Next;
    }
    return Penult;
}
/*  Конструкторы и деструктор*/
template <typename T>
Queue<T>::Queue():First(nullptr), Last(nullptr)
{

}

template <typename T>
Queue<T>::Queue(const Queue& Q2) //при присваивании и др. операциях мы создаем полностью независимую очередь.
{
    Node<T> *Slider, *Swap; //Slider бежит по адресам копируемого объекта. Swap для временного хранения указателя на новый узел.
    if(Q2.IsEmpty())
    {
        First=nullptr;
        Last=nullptr;
    }
    else
    {
        First=new Node<T>(Q2.First->NodeVal);
        First->Next=Q2.First->Next;
        Last=First; //для начала, указатель на последний узел указывает на тот же узел, что и указатель на первый узел.

        Slider=Q2.First->Next;
        while(Slider!=nullptr)
        {
            Swap=Last;
            Last=new Node<T>(Slider->NodeVal);
            Swap->Next=Last;
            Slider=Slider->Next;
        }
        Last->Next=nullptr; //наш цикл не устанавливает свойство Last->Next у текущего элемента, а только у предыдущего, поэтому мы вынуждены ставить его после цикла.
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

/*  Методы Push Pop GetFront IsEmpty*/
template <typename T>
bool Queue<T>::IsEmpty() const //константный метод для работы конструктора копирования.
{
    return First==nullptr;
}

template <typename T>
    void Queue<T>::Push(T NNodeVal)
    {
        Node<T>* Penult; //предпоследний
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
        Node<T>* Penult; //предпоследний
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
