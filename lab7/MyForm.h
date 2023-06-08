#pragma once
#include "Person.h"
#include "Notebook.h"


namespace lab7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ add_first;
	protected:

	private: System::Windows::Forms::TextBox^ phone_first;
	private: System::Windows::Forms::TextBox^ date_first;
	protected:


	private: System::Windows::Forms::TextBox^ fullname_first;
	private: System::Windows::Forms::TextBox^ fullname_second;
	private: System::Windows::Forms::TextBox^ date_second;
	private: System::Windows::Forms::TextBox^ phone_second;
	private: System::Windows::Forms::Button^ show_sim;








	private: System::Windows::Forms::Button^ show_first;
	private: System::Windows::Forms::Button^ add_second;
	private: System::Windows::Forms::Button^ show_second;



	private: System::Windows::Forms::TextBox^ outp_first;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ outp_second;
	private: System::Windows::Forms::TextBox^ outp_sim;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ plus2;
	private: System::Windows::Forms::Label^ plus1;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->add_first = (gcnew System::Windows::Forms::Button());
			this->phone_first = (gcnew System::Windows::Forms::TextBox());
			this->date_first = (gcnew System::Windows::Forms::TextBox());
			this->fullname_first = (gcnew System::Windows::Forms::TextBox());
			this->fullname_second = (gcnew System::Windows::Forms::TextBox());
			this->date_second = (gcnew System::Windows::Forms::TextBox());
			this->phone_second = (gcnew System::Windows::Forms::TextBox());
			this->show_sim = (gcnew System::Windows::Forms::Button());
			this->show_first = (gcnew System::Windows::Forms::Button());
			this->add_second = (gcnew System::Windows::Forms::Button());
			this->show_second = (gcnew System::Windows::Forms::Button());
			this->outp_first = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->outp_second = (gcnew System::Windows::Forms::TextBox());
			this->outp_sim = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->plus2 = (gcnew System::Windows::Forms::Label());
			this->plus1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// add_first
			// 
			this->add_first->Location = System::Drawing::Point(26, 124);
			this->add_first->Name = L"add_first";
			this->add_first->Size = System::Drawing::Size(140, 23);
			this->add_first->TabIndex = 0;
			this->add_first->Text = L"Add to file";
			this->add_first->UseVisualStyleBackColor = true;
			this->add_first->Click += gcnew System::EventHandler(this, &MyForm::add_first_Click);
			// 
			// phone_first
			// 
			this->phone_first->Location = System::Drawing::Point(26, 84);
			this->phone_first->Name = L"phone_first";
			this->phone_first->Size = System::Drawing::Size(140, 20);
			this->phone_first->TabIndex = 1;
			// 
			// date_first
			// 
			this->date_first->Location = System::Drawing::Point(172, 84);
			this->date_first->Name = L"date_first";
			this->date_first->Size = System::Drawing::Size(169, 20);
			this->date_first->TabIndex = 2;
			// 
			// fullname_first
			// 
			this->fullname_first->Location = System::Drawing::Point(26, 37);
			this->fullname_first->Name = L"fullname_first";
			this->fullname_first->Size = System::Drawing::Size(315, 20);
			this->fullname_first->TabIndex = 3;
			// 
			// fullname_second
			// 
			this->fullname_second->BackColor = System::Drawing::SystemColors::Window;
			this->fullname_second->Location = System::Drawing::Point(26, 212);
			this->fullname_second->Name = L"fullname_second";
			this->fullname_second->Size = System::Drawing::Size(315, 20);
			this->fullname_second->TabIndex = 7;
			// 
			// date_second
			// 
			this->date_second->Location = System::Drawing::Point(172, 259);
			this->date_second->Name = L"date_second";
			this->date_second->Size = System::Drawing::Size(169, 20);
			this->date_second->TabIndex = 6;
			// 
			// phone_second
			// 
			this->phone_second->Location = System::Drawing::Point(26, 259);
			this->phone_second->Name = L"phone_second";
			this->phone_second->Size = System::Drawing::Size(140, 20);
			this->phone_second->TabIndex = 5;
			// 
			// show_sim
			// 
			this->show_sim->Location = System::Drawing::Point(26, 482);
			this->show_sim->Name = L"show_sim";
			this->show_sim->Size = System::Drawing::Size(315, 25);
			this->show_sim->TabIndex = 9;
			this->show_sim->Text = L"Show similar";
			this->show_sim->UseVisualStyleBackColor = true;
			this->show_sim->Click += gcnew System::EventHandler(this, &MyForm::show_sim_Click);
			// 
			// show_first
			// 
			this->show_first->Location = System::Drawing::Point(172, 124);
			this->show_first->Name = L"show_first";
			this->show_first->Size = System::Drawing::Size(169, 23);
			this->show_first->TabIndex = 11;
			this->show_first->Text = L"Show output of a file";
			this->show_first->UseVisualStyleBackColor = true;
			this->show_first->Click += gcnew System::EventHandler(this, &MyForm::show_first_Click);
			// 
			// add_second
			// 
			this->add_second->Location = System::Drawing::Point(26, 308);
			this->add_second->Name = L"add_second";
			this->add_second->Size = System::Drawing::Size(140, 23);
			this->add_second->TabIndex = 12;
			this->add_second->Text = L"Add to file";
			this->add_second->UseVisualStyleBackColor = true;
			this->add_second->Click += gcnew System::EventHandler(this, &MyForm::add_second_Click);
			// 
			// show_second
			// 
			this->show_second->Location = System::Drawing::Point(172, 308);
			this->show_second->Name = L"show_second";
			this->show_second->Size = System::Drawing::Size(169, 23);
			this->show_second->TabIndex = 14;
			this->show_second->Text = L"Show output of a file";
			this->show_second->UseVisualStyleBackColor = true;
			this->show_second->Click += gcnew System::EventHandler(this, &MyForm::show_second_Click);
			// 
			// outp_first
			// 
			this->outp_first->Location = System::Drawing::Point(383, 21);
			this->outp_first->Multiline = true;
			this->outp_first->Name = L"outp_first";
			this->outp_first->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outp_first->Size = System::Drawing::Size(309, 143);
			this->outp_first->TabIndex = 16;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Contact name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 196);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Contact name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Phone number(without +)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 243);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(125, 13);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Phone number(without +)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(169, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(139, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Date of birth(DD-MM-YYYY)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(169, 243);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(139, 13);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Date of birth(DD-MM-YYYY)";
			// 
			// outp_second
			// 
			this->outp_second->Location = System::Drawing::Point(383, 193);
			this->outp_second->Multiline = true;
			this->outp_second->Name = L"outp_second";
			this->outp_second->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outp_second->Size = System::Drawing::Size(309, 143);
			this->outp_second->TabIndex = 23;
			// 
			// outp_sim
			// 
			this->outp_sim->Location = System::Drawing::Point(383, 364);
			this->outp_sim->Multiline = true;
			this->outp_sim->Name = L"outp_sim";
			this->outp_sim->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outp_sim->Size = System::Drawing::Size(309, 143);
			this->outp_sim->TabIndex = 24;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(380, 5);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(75, 13);
			this->label7->TabIndex = 25;
			this->label7->Text = L"First file output";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(380, 177);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(93, 13);
			this->label8->TabIndex = 26;
			this->label8->Text = L"Second file output";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(380, 348);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(70, 13);
			this->label9->TabIndex = 27;
			this->label9->Text = L"Similar output";
			// 
			// plus2
			// 
			this->plus2->AutoSize = true;
			this->plus2->Location = System::Drawing::Point(12, 262);
			this->plus2->Name = L"plus2";
			this->plus2->Size = System::Drawing::Size(13, 13);
			this->plus2->TabIndex = 28;
			this->plus2->Text = L"+";
			// 
			// plus1
			// 
			this->plus1->AutoSize = true;
			this->plus1->Location = System::Drawing::Point(12, 87);
			this->plus1->Name = L"plus1";
			this->plus1->Size = System::Drawing::Size(13, 13);
			this->plus1->TabIndex = 29;
			this->plus1->Text = L"+";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 531);
			this->Controls->Add(this->plus1);
			this->Controls->Add(this->plus2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->outp_sim);
			this->Controls->Add(this->outp_second);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->outp_first);
			this->Controls->Add(this->show_second);
			this->Controls->Add(this->add_second);
			this->Controls->Add(this->show_first);
			this->Controls->Add(this->show_sim);
			this->Controls->Add(this->fullname_second);
			this->Controls->Add(this->date_second);
			this->Controls->Add(this->phone_second);
			this->Controls->Add(this->fullname_first);
			this->Controls->Add(this->date_first);
			this->Controls->Add(this->phone_first);
			this->Controls->Add(this->add_first);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void add_first_Click(System::Object^ sender, System::EventArgs^ e);


private: System::Void show_first_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void add_second_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void show_second_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void show_sim_Click(System::Object^ sender, System::EventArgs^ e);

};
}
