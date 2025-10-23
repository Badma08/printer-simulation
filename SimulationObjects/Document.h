#pragma once

namespace SimulationObjects
{
	public ref class Document
	{
	private: // ����
		int _pageCount;
		array<System::String^>^ _colors;

	public:
		// ������������
		Document(int pageCount);
		Document(int pageCount, array<System::String^>^ colors);
		// ��������
		property int PageCount {
			int get();
			void set(int value);
		}
		// �������
		bool IsColor();
		System::String^ GetPageColor(int pageIndex);
	};
}
