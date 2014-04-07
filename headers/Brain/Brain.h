namespace Brain {
	ref class Core {
	public:
		// ����������� ����
		Core();	





		//
		// ������:
		//
		
		// ������� ������� ��������������� ����������
		void SetSens();
		
		// �������� ��������� ��������� ��������� ����������
		void PatCreate();	
		
		// ���� �����
		void Wave();

		// ������� ����� ��������� ����
		void CalcFields();

		// ��������� ������� � ��������� �����
		void S0(int %ix, int %iy);

		// �������� �������������� ������������ ��������
		void S1(int %ix, int %iy);

		// ������ ���������� �����
		void DrawChart();

		// ��������� �� ������������ ��� �������� ����������������� ������ 
		void Draw_Status();
		
		// ������������ ����� ��������
		void addpic();

		// ������ ��������� ����������
		void Calc_Evoked_Activity();
		
		// �������� ������������� �����. ������� �����������
		void LearnW1();
		
		// ������� ��������� ��������
		void Draw_Learn();

		// �������� �� ��������� �������
		void TMove();

		// ������� ��������� ����������
		void Draw_EvokedA();

		// ������� ����������� ����������
		void Draw_ActAccum();

		// ������� ���� ���������� (��������)
		void Draw_FieldA();

		// ������� ����������
		void Draw_RelaxA(int ntype);

		// ������� ���� ����� (��������)
		void Draw_WaveA();

		// ��������� ������� ������� �������
		void Draw_Numbers();
		
		// ��������� ������� ���������
		void PatternsActivation();

		// ���������� ������� �������� ������� �������
		void ActivePatternsRefresh();

		// ������������� �����
		void InitCore();

		// ������� ���� ����������, ������������ �� �������� (���� ����� �� ������������)
		// void MakePicAAvg();






		//
		// ����:
		//
		
		// ���-�� ����� ��������
		int N_Types;
		// ������� ���������������� ������������� � ���������������� ���������� � ����������, ������������ �������� �������� ������� ����
		array<unsigned short, 3> ^SensTable;
		
		// ������� ����
		int X_C;
		int Y_C;

		// �������� ��������: ����
		System::Drawing::Bitmap ^pic;
		System::Drawing::Graphics ^Gpic;
		
		// ����� ���������� ���������
		int NP;
		// ����������� (������� �.�.):
		// ���� ���� � ��������� ��������� ����������, ������� ������������ �������� ������� �����

		// ����������� (������� �.�.):
		// ���������, ������� ��������� ���� ������� ��������� ����������
		value class Pattern {
		public:
			// ������ ���������
			int ix;
			int iy;

			array<unsigned short, 2> ^P;
		};
		// ����� ��������� ��������� ���������� // ������� �.�.: �.�. ������� ������� (�� ������ ��������� ����)
		array<Pattern> ^PatSet;

		// ������ �������� ��������� ����������
		int R_Pat;

		// ���-�� �������� � ������� ��������� ����������
		int NNPat;

		// ����������� (������� �.�.):
		// ���������, ����������� ���� �� ������ ��������������� ��� ������� �������
		value class ID {
		public:
			// 0 - �� ��������������
			// 1 - ��������������
			int ConsStatus;

			int NAct;
			int TCreat;

			int NP; // ����� �������� ��� �������� �� ����� �������
			//
			// ������� �.�.: ���� � ��������� �������, �� ��� ����� �������� ��������� ����������,
			//				 ������� ������� ������ ����������������� ������� (�����)
			//

			array<unsigned short, 2> ^P;
		};
		// ����������� (������� �.�.):
		// ���������, ����������� ��������� ������� �� ����
		value class Neuron {
		public:
			// ��� �������
			unsigned short Type;
			// 0 - ������� �����
			// 1 - ������ ������� ������ (��������)
			// 2 - ������ ������� ������

			// ������� ������ �������
			unsigned short Status;
			// 0 - ������� // ����������� (������� �.�.): ������
			// 1 - ��������� ���������� // ����������� (������� �.�.): �������
			// 2 - �������� ���������� // ����������� (������� �.�.): �����
			// 3 - ������ ���� �������� ����������
			// 4 - ���������� ����� ��������� ������ // ����������� (������� �.�.): �����
			// 5 - ���������� ���������� // ����������� (������� �.�.): �������
			// 6 - ������� �����
			// 7 - ��������� �������� �� ��������� ������� � �������� ��������������

			// ����������� �� ����� �������� �������� ����������
			float AAccumSinapse;

			// ����������� �� ����� �������� ���������������� ���������� ����������
			float AAccumExtraSinapse;

			// ��������� �������
			int T;

			// ��������� ��������� ���������� ������� � ���������� ���������
			float EvokedA;

			// ������� ������ �������� �������
			unsigned short StatusL;
			// 0 - ��������
			// 1 - �����������
			// 2 - ������
			// 5 - �� �������� �������� (������� �����)
			// ������� �.�.: � ��� 3 � 4? �������� ������� � ����, ��� 5 ��������� � ��������� ��������� ��������� ����������,
			// ������� ������ ���� ��������� �����, ������� �� �������� � ������������ �� �������� �������� ����������� ������

			// ��������� ������� ��������
			int TL;

			// ����� ������ �������������� �������������� ��� ������� �������
			System::Collections::ObjectModel::Collection<ID> ^ID;

			bool ERR;
		};
		// ����
		array<Neuron, 2> ^Cortex;

		// ������ ���������� �������� � ������������� ��������� ��� ������� �� �����. ���� ����� ������� ����������� ���������� ����������
		array<double> ^LImin;
		
		// ���������� �������� �� ����������� ��� ID (����� � ������ �� ����������� � ���������)
		// ������� �.�.: ��� ������������� ����������
		int R_ID;
		// ���������� �������� �� ����������� ��� ����� W (����� � ������ �� ����������� � ���������)
		// ������� �.�.: ��� ������������� ����������
		int R_W;
		// ������ ��������������� ����������. ������ � �������� ���������� �� �������� (������� ���������)
		int RLAM;
		// ������ ������������� ����������
		int NLocalAM;
		array<float, 2> ^LocalAM;
		// �������� ��������������� ����������. ���������
		float Sigma2LAM;

		// ������� ����
		int CT;

		// ������ ���������� �������������� ���������� (������)
		int TAhalf;
		// ������� ���������� �� ���� ����
		float KA;
		
		// ���� ����������� ��������� ���������� ����
		array<float, 2> ^Field_A_Accum;
		// ����� ���������� ��������� ���������� ��� ����������� ��������
		float L_ActL1;
		
		// ���� ���������� ���������� ����
		array<float, 2> ^Field_A;
		// ����� ���������� �� �������� ��� ����������� ��������
		float L_ActLS;

		// ���� ��������� ���������� ����
		array<float, 2> ^Field_A_Evoced;
		// ���� �������� ���������� ����
		array<float, 2> ^Field_A_Wave;
		// ���� ��������� ������������� �������� ������� �� �����
		array<float, 3> ^Field_A_Relax;

		// ����������������� ������ ����������������� ����������
		int T_ID;
		// ����������������� ������
		int T_Passive;
		// ����� ������ ���������� ���������� ��� ������������� ��������
		int T_SinapseLearn;
		// ����� ����� ��������� ��������� ��������
		array<unsigned short, 3> ^CortexA;
		// ����� ������ ���������� ���������� ��� ���������������� ��������
		int T_ExtraSinapseLearn;

		// ����������� ���������� ��� ������ �������
		double LAmin;
		// ������ ���������� ��� ��������� ���������� �������
		double LAmax;

		// ����� ��������� �� ��������������
		double L_act;
		
		// ���������� ����, ����������� ��� ������������
		int NCons;

		// ������� �.�.: ��������� ��������� ��� ������������� ��������� ��������� ����������
		System::Collections::ObjectModel::Collection<int> ^CheckedPatterns;

		// ����������� ������� ����������� ������
		double Psp;
		
		// ������� ����
		int CurLayer;

		// ��������� ����������� ����������
		int NSer;
		int CurPosA;
		array<double> ^AWave;

		// ������ ���������� �����
		System::Drawing::Bitmap ^pic2;

		// ������� �.�.: ���������� ���� (��� �������� ��������)
		Brain::Core ^cortex0;
		// ��������� ���� ���� // ������� �.�.: ��������� ����
		Brain::Core ^cortex2;
		
		// ���������� ���� ���������� �������
		int TX1;
		int TY1;
		// ���������� ���� ��������� �������
		int TX2;
		int TY2;
		// ������� �������
		int TD;

		// ��������� ��� ������������ ������� ����� ���������
		bool FPic; // ������� �.�.: ���� ����, ���� ��� �� ���� ������� ����� �������� ���������� �� �������
		int PicStart; // ������� �.�.: ���� (������ �������), ������� � �������� ���� ������ �������� �������� � ���������� NPic
		int NPic; // ������� �.�.: ���������� ��������
		int WPic; // ������� �.�.: ���������� �������� �� �����������
		System::Drawing::Bitmap ^Bigpic;

		// ������� ������������������ �����
		array<int> ^LayersSequence;

		// ���� ��������� �������� ��������-����������
		bool FLearn;

		// ���� �������� ��������
		// ������� �.�.: ������, ������ ������ ������ �� ����� �������� (�� ���������� <= R_W) ���������, � ��� �� ����
		array<float, 4> ^CortexW;

		// ����� ��������� �������
		float L_Spike;

		// ����������������� ��������� ����������
		int T_EnvokedA;

		// ������� ��������� ��������
		System::Drawing::Bitmap ^pic1;
		
		// ������������ ���������������� ���������������
		// ����� �������� �� �����������
		double L_GameLive_Low;
		// ����� �������� �� �������������
		double L_GameLive_high;

		// ������� ��������� ����������
		System::Drawing::Bitmap ^picEvokedA;
		// ������� ����������� ����������
		System::Drawing::Bitmap ^picActAccum;
		// ������� ���� ���������� (��������)
		System::Drawing::Bitmap ^picFieldA;
		// ������� ����������
		System::Drawing::Bitmap ^picRelaxA;
		// ������� ���� ����� (��������)
		System::Drawing::Bitmap ^picWaveA;

		// ������� ���� ����������, ������������ �� �������� (�� ������������)
		// System::Drawing::Bitmap ^picAAvg;

		//-----------------------------------------------------------------------------------------------
		// ������� �.�.: ��� ���� �� ������������:
		/*
		// ������� ���� ���������� ����������
		int SReceptF;
		// ���������� �������� ��������� � ������ �����
		int NPC;
		// ������� 
		int N_Neurotransmitters;
		// �����, ���������� �� ������������
		int T_L1;
		*/

	private:
		// ��������� ��������� ������������ ����� �� 0 �� 1
		System::Random ^rnd;
	};
}