#include "pch.h"
#include "Document.h"

namespace SimulationObjects
{
    // ������������ � �����������
    Document::Document(int pageCount)
    {
        _pageCount = pageCount;
    }

    Document::Document(int pageCount, array<System::String^>^ colors)
    {
        _pageCount = pageCount;
        _colors = colors;
    }
    // ��������
    int Document::PageCount::get() 
    {
        return _pageCount;
    }

    void Document::PageCount::set(int value)
    {
        _pageCount = value;
    }
    // ������
    bool Document::IsColor() // ���������, ���� �� ������ ������
    {
        if (_colors == nullptr)
            return false;

        return true;
    }

    System::String^ Document::GetPageColor(int pageIndex) // ���������� ���� �������� �� ���������� �������
    {
        return _colors[pageIndex];
    }
}
