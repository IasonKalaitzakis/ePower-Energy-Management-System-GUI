The Energy Management System of the Multiport Power Converter (MPC) circuit is controlled through the ePOWER GUI application software. This user’s guide provides instructions on how to use the features of the ePOWER GUI in order to communicate with the optimization and real-time controller modules of the LAUNCHXL-F28379D controller.

System Requirements

The following list shows the system requirements for the GUI application to properly run and communicate with the peripherals:

	PC with any Intel or AMD x86-64 processor
	MathWorks™ MATLAB software, version 2020a or higher
	Windows, Linux or macOS compatible with MATLAB version
	512 MB of RAM
	100 MB of free hard-disk space
	USB port (in case of serial communication)
	Internet Access
 
Installation

The ePOWER GUI application requires no installation, and is run by executing the .exe file. 
However, it requires the installation of the aforementioned MATLAB software with the Control System Toolbox and Deep Learning Toolbox.

User Interface Overview

![pic2](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/f49d8288-40eb-4b4b-b90b-66d6d4e7ef2a)

Executing the .exe file launches the main optimization window as seen. The ePOWER GUI comprises the following sections:

	Modules and Parameters: The modules that connect to the multiport converter are displayed in this section, along with the option to enable/disable them and parametrize them.
	Communication: The two communication options provided are through serial (USB) and Wi Fi. 
	Real-time values: The feedback values provided by the real-time controller are displayed here, in order to ensure the correct operation of the converter.
	GUI Status: Current runtime status of the user interface.
 
Modules and Parameters

Each module can be included or excluded, and parametrized accordingly. A more detailed explanation on the parametrization of each module is provided in the following paragraphs.

Electric Vehicle Battery

The batteries follow load convention:
Positive power means power flow from the converter to the battery.
Negative power means power flow from the battery to the converter.


The following list contains information on each parametrizable value of the EV battery:

    P_max: Maximum power flow from the converter to the charger (kW).
    P_min: Maximum power flow from the charger to the converter (kW). 
    Capacity: Rated capacity of the battery (kWh).
    Converter Efficiency: Efficiency of the converter between requested energy and true energy consumption (0-1).

The electric vehicle additionally supports a commute routine, in which the user can schedule a specific commute time range in which the EV will be absent:

    SoC_commute: Approximate energy consumption of the EV during the commute (kWh).
    EV Departure hour: Departure hour of the scheduled absence of the EV (hours).
    EV Return hour: Return hour of the scheduled absence of the EV (hours).

Battery pack

The battery pack module is parametrized similarly to the EV battery:

    P_max: Maximum power flow from the converter to the battery (kW).
    P_min: Maximum power flow from the battery to the converter (kW).
    Capacity: Rated capacity of the battery (kWh).
    Converter Efficiency: Efficiency of the converter between requested energy and true energy consumption (0-1).

Load Shifting

The load shifting module is used to define a load shifting percentage of the home load at each time step, allowing up to that percentage of load-shedding/load-addition of kilowatts: 

    Load_shifting: Maximum percentage of allowed load shifting (%).
    
Grid-converter limits

The user can define maximum and minimum power flow between the converter and the grid, according to the converter’s limits (load convention applies, same as before):

    P_grid_max: Maximum power flow from the grid to the converter (kW).
    P_grid_min: Minimum power flow from the converter to the grid (kW). 

Solar Panels

The solar panel power output prediction that is executed at the start of optimization requires the user to input the rated power of the PV array:

    Rated Power: Rated power of the PV array (kW).

Thermodynamic Model

The user is asked to provide the physical properties of the residence, as well as the operational limits of the heating/cooling system:

    Air density, ρ: Density of the air (kg/m3).
    Heat Capacity, C: Heat capacity of the air in the building [kJ/(kg x oC)]. 
    Air volume, V: Volume of the air (m3).
    aw: Absorbance coefficient of the external surface of the wall, according to Beer-Lambert law.
    Rsej: External surface heat resistance for convection and radiation of external walls (m3 x oC /W(m^2  ∙ °C)/W).
    Uwall: Heat transfer coefficient of the wall of the building [kW/(m3 x oC(m^2  ∙ °C)/W)].
    Uwindow: Heat transfer coefficient of the windows of the building [kW/(m3 x oC(m^2  ∙ °C)/W)].
    Wall surface: Total wall surface, including roof surface (m^22).
    Window surface: Total window surface (m^22).
    τwindow: Glass transmission coefficient of the windows.
    SC: Shading coefficient of the windows.
    Maximum Heating/Cooling Power: Maximum operational limit of the heating/cooling system (kW).
    Minimum Heating/Cooling Power: Minimum operational limit of the heating/cooling system (kW).
    COP: Coefficient of Performance, the relationship between the power (kW) that is drawn out of the heat pump as cooling or heat, and the power (kW) that is supplied to the compressor.

Communication

The ePOWER GUI can communicate with the control of the circuit through either serial communication or Wi-Fi.

Serial communication

The serial communication is performed through the Wi-Fi card CC3200-LAUNCHXL, with the user’s PC connected to the card via USB. The GUI requires the specific COM port of the card in order to connect properly. The COM port info can be located and edited in the Device Manager setting of Windows, along with the baud-rate of the device. It is recommended to set the baud-rate (through the device manager) to at least 115200, due to the large amount of information that needs to be passed to the peripherals.

Once the settings are configured, the user can press Connect to establish a connection with the system to read the real-time values and initialize the optimization. While the user remains connected, the real-time values are saved in the RealTime_*.txt files with a 5-minute interval.

It is important to press the Disconnect button once the connection is no longer needed, in order to properly deallocate and delete the connection and file streams.

Wi-Fi communication

The user’s PC requires an Internet connection to connect with the Wi-Fi card over the Internet.  The user is required to input the webserver info (IP and port) of the server established by the Wi-Fi card in order to connect.

The Connect and Disconnect buttons operate with the same principle as above.

Real-time values
The real-time values are received through whichever communication option is chosen, and are shown in the lower left section of the ePOWER GUI. The power, SoC, voltage and current values are saved in the RealTime_*.txt files every 10 seconds, as long as the GUI is connected to the controller. The real-time values of the ancillary services of the MPC are saved in the .txt file.
![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/340ad0e6-b0c0-4ec6-a64c-e7b3acf1518c)
![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/f0ad83e1-688b-49a3-8bc6-97847ef52a33)
![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/5b4fe9a5-85ec-4ca8-b69f-6d295f15b7df)
![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/b664b97d-9c60-40eb-9a8c-b891fcb63d7f)


	Vev: Electric Vehicle voltage (V)
	Iev: Electric Vehicle current (A)
	Vbat: Battery Pack voltage (V)
	Ibat: Battery Pack current (A)
	Vsc: Supercapacitor voltage (V)
	Isc: Supercapacitor current (A)
	Vpv: PV array voltage (V)
	Ipv: PV array current (A)
	Vg,a: Grid voltage, phase A (V)
	Vg,b: Grid voltage, phase B (V)
	Vg,c: Grid voltage, phase C (V)
	Ig,a: Grid current, phase A (A)
	Ig,a: Grid current, phase B (A)
	Ig,a: Grid current, phase C (A)
	Vdc: DC link voltage (V).
 
The real-time values of power and SoC are:

	Pev: Electric Vehicle power (W)
	Pbat: Battery Pack power (W)
	SoCev: Charge level of Electric Vehicle battery (%)
	SoCbat: Charge level of Battery Pack (%)
	Ppv: PV array power (W)
	Psc: Supercapacitor power (W)
	Pgrid: Power transfer between converter and electric grid (W).
 
The real-time ancillary services and their associated values are:

	Freq.Sup.: Frequency support signal (Yes/No)
	Volt.Sup.: Voltage support signal (Yes/No)
	ΔP: Change of active power to support grid frequency (W)
	Red.Load.: Percentage of load reduction requested by the grid operator (%)
	ΔL: Reduced load demand after request by the grid operator (W)
	ΔQ: Change of reactive power to support grid voltage (VAR).

Advanced settings

The advanced settings panel can be toggled by selecting the advanced settings checkbox seen below. 
 ![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/9945a0d2-09d8-438a-ba2b-8ebbffefbc74)

The first section of the panel contains two of the basic Particle Swarm Optimization parameters, particles and epochs: 

	Particles: The number of particles dictates how quickly the optimization will reach the optimal solution. Due to memory limits of the LAUNCHXL-F28379D controller, the maximum number of particles is set to 10.
	Epochs: Total iterations of the optimization. Raising the number of epochs increases the chance of reaching an optimal solution, but also the optimization runtime. Unlike particles, there is no operational limit to the number of epochs.
	Save folder: The file folder in which all the files associated the optimization and real-time operation are saved (real-time values, optimization inputs and results, etc.).
	IP of data aggregator: The IP of the data aggregator from which the daily energy cost, environmental temperature, solar irradiance and support signal arrays are pulled, and the optimization results and real-time values are sent, in order to be directed to the proper entities.

Data aggregator server

Using the python file provided, the user can use a host PC to set up the data aggregator server and communicate with the ePOWER GUI. The server can be on the same PC as the GUI or a different one, as long as the IP and Port of the aforementioned setting are configured correctly. 

The server is used to send the environmental temperature, solar irradiance and support signal arrays located in the host PC’s “User\Documents\ePOWER” folder to the GUI. 

Regarding the format of the input arrays: the temperature file needs to be named “temperature.txt”, and contain 48 float values, separated by tabs, with the temperature (°C) of the next 24 hours in half hour intervals. The energy cost (€/kWh) file needs to be named “cost.txt” and follow the same format. The solar irradiance (W/m2) file also follows the same format, and needs to be named “irradiance.txt”. 

The support signals are provided through the files “frequency_support.txt” for frequency support, “voltage_support.txt” for voltage support, and “load_reduction.txt” for load reduction. The first two files consist of 0 or 1 Boolean values, with a time interval of 10 seconds for a total of 8640 values, separated by tabs. The load reduction file consists of load reduction percentages (%) requested by the power aggregator, with the same format as above.

Optimization results, real-time values and ancillary services results are sent to the server by the GUI and saved in “User\Documents\ePOWER\GUI_Output” of the host’s PC. The real-time values of the Electric Vehicle are sent to Electric Vehicle Server Provider (EVSP) and to the Electric Vehicle Transaction Operator (EVTO) as seen in the .txt file. The optimization output and real-time grid power exchange values are sent to the power aggregator as seen below.

![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/7b02567a-4e3d-4404-966a-664565381025)
![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/b892c965-03c2-44c7-a932-b0dd838d3761)
![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/7c571c44-2136-4e86-b5e2-9a0ce9d18b0e)

The real-time values transmitted to the aforementioned entities are the following:

	Pev: Electric Vehicle power (W)
	Vev: Electric Vehicle voltage (V)
	Iev: Electric Vehicle current (A)
	SoCev: Charge level of Electric Vehicle battery (%).
 
The .txt file shown above contains the power Pgrid time series output of optimization that the MPC exchanges with the grid. The real-time values of the grid-side of the MPC are depicted. More specifically:

	Vg,a: Grid voltage, phase A (V)
	Vg,b: Grid voltage, phase B (V)
	Vg,c: Grid voltage, phase C (V)
	Ig,a: Grid current, phase A (A)
	Ig,a: Grid current, phase B (A)
	Ig,a: Grid current, phase C (A)
	Pgrid: Power transfer between converter and grid (W).
 
Real-time values are transferred between the GUI PC and the webserver PC automatically every 30 minutes. The optimization related data is transferred each time the optimization is executed, which is by default every 24 hours.

‘Run optimization’ button 

Once all settings are properly configured, and the GUI is connected to the controller either through serial or Wi-Fi, the user can initiate the optimization by clicking “Run Optimization”. The application first executes the load prediction algorithm, and the PV production prediction algorithm. Afterwards, the GUI transfers the required data to the Wi-Fi card, which is then passed on to the optimization controller.

Once optimization is finished, the results are sent to both the real-time controller and the GUI, the latter of which saves them in files. When the “Plot Optimization” button turns on, that means the optimization results have been received, and the user can choose to plot the results. 
![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/6b01a6db-7bb3-41fb-8910-5c182baa8c7f)
![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/00fd8e04-e974-475b-950b-166f033ca531)
![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/1fc39a1f-2bc5-451a-afbd-6adbce5ccb47)
![image](https://github.com/IasonKalaitzakis/ePower-Optimal-Power-Management-Graphical-User-Interface/assets/31860283/8c49cc75-ad6f-407c-99d8-3ebb1e8dd483)

 
The .txt file of the optimization input arrays are:

	Tout: Environmental temperature (°C)
	Ppv: PV array power production forecast (W)
	Cost: Energy cost (€/kWh)
	Pload: Load demand forecast (W).

The results of the optimization are fed to the controller and also saved in the .txt file shown in Fig.11, as follows:

	Pev: Electric Vehicle power set-point (W)
	Pbat: Battery Pack power set-point (W)
	SoCev: Charge level of Electric Vehicle battery (%)
	SoCbat: Charge level of Battery Pack (%)
	Pthermal: Heating/cooling system power (W)
	Tin: Indoors temperature (°C)
	Ploadshift: Load demand after load shifting has been applied (W).
