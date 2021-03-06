/*********************************************************************
 * Name:      	main.cpp
 * Purpose:   	Implements simple wxWidgets application with GUI
 * 				created using wxFormBuilder.
 * Author:
 * Created:
 * Copyright:
 * License:   	wxWidgets license (www.wxwidgets.org)
 *
 * Notes:		Note that all GUI creation code is implemented in
 * 				gui.cpp source file which is generated by wxFormBuilder.
 *********************************************************************/

#include "main.h"

// initialize the application
IMPLEMENT_APP(MainApp);

////////////////////////////////////////////////////////////////////////////////
// application class implementation
////////////////////////////////////////////////////////////////////////////////

bool MainApp::OnInit()
{
    SetTopWindow(new MainFrame(NULL));
    GetTopWindow()->Show();
    // true = enter the main loop
    return true;
}

////////////////////////////////////////////////////////////////////////////////
// main application frame implementation
////////////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxWindow* parent)
    : MainFrameBase(parent)
{
}

MainFrame::~MainFrame()
{
}

void MainFrame::OnCloseFrame(wxCloseEvent& event)
{
    Destroy();
}

void MainFrame::OnExitClick(wxCommandEvent& event)
{
    Destroy();
}

// Случайные числа в таблицу
void MainFrame::onRand(wxCommandEvent& event)
{
    std::srand(time(0)); // Инициализация датчика случайных чисел
	int rc = m_grid1->GetNumberRows(); // Определяем количество строк в таблице
    int cc = m_grid1->GetNumberCols(); // Определяем количество столбцов в таблице
    // Перебираем все строки таблицы
    for(int i = 0; i < rc; i++) {
	// Перебираем все столбцы таблицы
	for(int j = 0; j < cc; j++) {
	    int r = std::rand() % 41 - 20; // Генерируем случайное число
	    m_grid1->SetCellValue(i, j, wxString::Format("%d", r)); // Занесем в ячейку таблицы нужное значение
	}
    }
    // Программно нажмем на кнопку расчета суммы
    onSum(event);
}

// Сумма чисел в таблице
void MainFrame::onSum(wxCommandEvent& event)
{
    int rc = m_grid1->GetNumberRows(); // Определяем количество строк в таблице
    int cc = m_grid1->GetNumberCols(); // Определяем количество столбцов в таблице
    int sum = 0;
    wxString ss;

    // Перебираем все строки таблицы
    for(int i = 0; i < rc; i++) {
	// Перебираем все столбцы таблицы
	for(int j = 0; j < cc; j++) {
	    ss = m_grid1->GetCellValue(i, j); // Считываем текстовое значение ячейки таблицы
	    sum += strtol(ss, NULL, 0); // Накапливаем в переменной значение суммы, преобразовав в число значение ячейки
	}
    }
    m_staticText_Sum->SetLabel(L"Сумма = " + wxString::Format("%d", sum)); // Выдадим в компонент значение суммы
}