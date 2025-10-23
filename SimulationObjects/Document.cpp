#include "pch.h"
#include "Document.h"

namespace SimulationObjects
{
    // конструкторы с параметрами
    Document::Document(int pageCount)
    {
        _pageCount = pageCount;
    }

    Document::Document(int pageCount, array<System::String^>^ colors)
    {
        _pageCount = pageCount;
        _colors = colors;
    }
    // свойства
    int Document::PageCount::get() 
    {
        return _pageCount;
    }

    void Document::PageCount::set(int value)
    {
        _pageCount = value;
    }
    // методы
    bool Document::IsColor() // провер€ет, есть ли массив цветов
    {
        if (_colors == nullptr)
            return false;

        return true;
    }

    System::String^ Document::GetPageColor(int pageIndex) // ¬озвращает цвет страницы по указанному индексу
    {
        return _colors[pageIndex];
    }
}
