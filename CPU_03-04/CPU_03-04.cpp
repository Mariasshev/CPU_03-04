#include <iostream>
using namespace std;

class GPU 
{
public:
    bool StartGPU() {
        cout << "������ ����������" << "\n";

        return true;
    }
    bool CheckConnectWithMonitor() 
    {
        cout << "�������� ����� � ���������" << "\n";

        return true;
    }
    bool ShowDataAboutWinch() 
    {
        cout << "����� ������ � ����������" << "\n";

        return true;
    }
    bool DisplayingDataAboutTheRAM() 
    {
        cout << "����� ������ �� ����������� ������" << "\n";

        return true;
    }
    bool ShowMessageOnMonitor() 
    {
        cout << "������� �� ������� ������ ���������� ���������" << "\n";

        return true;
    }
};
class RAM 
{
public:
    bool StartRAM() 
    {
        cout << "������ ����������� ������" << "\n";
        return true;
    }
    bool MemoryAnalysis() 
    {
        cout << "������ ������" << "\n";
        return true;
    }


    bool MemoryClearing() 
    {
        cout << "������� ����������� ������" << "\n";
        return true;
    }
};
class Winchester 
{
public:
    bool StartWinchester() 
    {
        cout << "������ ����������" << "\n";
        return true;
    }
    bool BootSectorCheck() 
    {
        cout << "�������� ������������ �������" << "\n";
        return true;
    }


    bool StoppingTheDevice() 
    {
        cout << "��������� ���������� (����������)" << "\n";
        return true;
    }
};
class PowerUnit 
{
public:
    bool ServeFood() 
    {
        cout << "������ �������" << "\n";
        return true;
    }
    bool SupplyPowerToTheGPU() 
    {
        cout << "������ ������� �� ����������" << "\n";
        return true;
    }
    bool SupplyPowerToTheRAM() 
    {
        cout << "������ ������� �� ����������� ������" << "\n";
        return true;
    }
    bool SupplyPowerToTheWinchester() 
    {
        cout << "������ ������� �� ���������" << "\n";
        return true;
    }
    bool StopPoweringTheGPU() 
    {
        cout << "���������� ������� ����� �����" << "\n";
        return true;
    }
    bool StopPoweringTheRAM() 
    {
        cout << "���������� ������� ����������� ������" << "\n";
        return true;
    }
    bool StopPoweringTheWinchester() 
    {
        cout << "���������� ������� �����������" << "\n";
        return true;
    }
    bool Shutdown() 
    {
        cout << "���������� ����� �������" << "\n";
        return true;
    }
};

class Sensors 
{
public:
    bool CheckVoltage() 
    {
        cout << "��������� ����������" << "\n";
        return true;
    }
    bool CheckTempInPowerUnit() 
    {
        cout << "��������� ����������� � ����� �������" << "\n";
        return true;
    }
    bool CheckTempInGPU() 
    {
        cout << "��������� ����������� � ����������" << "\n";
        return true;
    }
    bool CheckTempInRAM() 
    {
        cout << "��������� ����������� � ����������� ������" << "\n";
        return true;
    }
    bool CheckTempOfAllSystems() 
    {
        cout << "��������� ����������� ���� ������" << "\n";
        return true;
    }
};


class PC 
{
    GPU* gpu;
    RAM* ram;
    Winchester* winchester;
    PowerUnit* powerUnit;
    Sensors* sensors;

public:
    void BeginWork() 
    {
        powerUnit->ServeFood();
        sensors->CheckVoltage();
        sensors->CheckTempInPowerUnit();
        sensors->CheckTempInGPU();
        powerUnit->SupplyPowerToTheGPU();
        gpu->StartGPU();
        gpu->CheckConnectWithMonitor();
        sensors->CheckTempInRAM();
        powerUnit->SupplyPowerToTheRAM();
        ram->StartRAM();
        ram->MemoryAnalysis();
        gpu->DisplayingDataAboutTheRAM();
        powerUnit->SupplyPowerToTheWinchester();
        winchester->StartWinchester();
        winchester->BootSectorCheck();
        gpu->ShowDataAboutWinch();

        sensors->CheckTempOfAllSystems();
    }

    void FinishWork() 
    {
        winchester->StoppingTheDevice();

        //RAM
        ram->MemoryClearing();
        ram->MemoryAnalysis();
        gpu->ShowMessageOnMonitor();

        //power unit
        powerUnit->StopPoweringTheGPU();
        powerUnit->StopPoweringTheRAM();
        powerUnit->StopPoweringTheWinchester();

        sensors->CheckVoltage();
        powerUnit->Shutdown();
    }
};



int main() 
{
    setlocale(LC_CTYPE, "Russian");
    PC* pc = new PC();
    pc->BeginWork();
    cout << "----------------" << endl;;
    pc->FinishWork();
    delete pc;

    return 0;
}
