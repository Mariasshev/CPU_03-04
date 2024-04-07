#include <iostream>
using namespace std;

class GPU 
{
public:
    bool StartGPU() {
        cout << "Запуск видеокарты" << "\n";

        return true;
    }
    bool CheckConnectWithMonitor() 
    {
        cout << "Проверка связи с монитором" << "\n";

        return true;
    }
    bool ShowDataAboutWinch() 
    {
        cout << "Вывод данных о винчестере" << "\n";

        return true;
    }
    bool DisplayingDataAboutTheRAM() 
    {
        cout << "Вывод данных об оперативной памяти" << "\n";

        return true;
    }
    bool ShowMessageOnMonitor() 
    {
        cout << "Вывести на монитор данные прощальное сообщение" << "\n";

        return true;
    }
};
class RAM 
{
public:
    bool StartRAM() 
    {
        cout << "Запуск оперативной памяти" << "\n";
        return true;
    }
    bool MemoryAnalysis() 
    {
        cout << "Анализ памяти" << "\n";
        return true;
    }


    bool MemoryClearing() 
    {
        cout << "Очистка оперативной памяти" << "\n";
        return true;
    }
};
class Winchester 
{
public:
    bool StartWinchester() 
    {
        cout << "Запуск винчестера" << "\n";
        return true;
    }
    bool BootSectorCheck() 
    {
        cout << "Проверка загрузочного сектора" << "\n";
        return true;
    }


    bool StoppingTheDevice() 
    {
        cout << "Остановка устройства (винчестера)" << "\n";
        return true;
    }
};
class PowerUnit 
{
public:
    bool ServeFood() 
    {
        cout << "Подать питание" << "\n";
        return true;
    }
    bool SupplyPowerToTheGPU() 
    {
        cout << "Подать питание на видеокарту" << "\n";
        return true;
    }
    bool SupplyPowerToTheRAM() 
    {
        cout << "Подать питание на оперативную память" << "\n";
        return true;
    }
    bool SupplyPowerToTheWinchester() 
    {
        cout << "Подать питание на винчестер" << "\n";
        return true;
    }
    bool StopPoweringTheGPU() 
    {
        cout << "Прекратить питание видео карты" << "\n";
        return true;
    }
    bool StopPoweringTheRAM() 
    {
        cout << "Прекратить питание оперативной памяти" << "\n";
        return true;
    }
    bool StopPoweringTheWinchester() 
    {
        cout << "Прекратить питание винчестеров" << "\n";
        return true;
    }
    bool Shutdown() 
    {
        cout << "Выключение блока питания" << "\n";
        return true;
    }
};

class Sensors 
{
public:
    bool CheckVoltage() 
    {
        cout << "Проверить напряжение" << "\n";
        return true;
    }
    bool CheckTempInPowerUnit() 
    {
        cout << "Проверить температуру в блоке питания" << "\n";
        return true;
    }
    bool CheckTempInGPU() 
    {
        cout << "Проверить температуру в видеокарте" << "\n";
        return true;
    }
    bool CheckTempInRAM() 
    {
        cout << "Проверить температуру в оперативной памяти" << "\n";
        return true;
    }
    bool CheckTempOfAllSystems() 
    {
        cout << "Проверить температуру всех систем" << "\n";
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
