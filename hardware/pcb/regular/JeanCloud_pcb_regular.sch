EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "JeanCloud PCB"
Date "2021-10-17"
Rev "0.1.1"
Comp "TrveLabs"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L dk_USB-DVI-HDMI-Connectors:10118193-0001LF J1
U 1 1 616C52EC
P 2200 3500
F 0 "J1" H 2264 4245 60  0000 C CNN
F 1 "10118193-0001LF" H 2264 4139 60  0000 C CNN
F 2 "digikey-footprints:USB_Micro_B_Female_10118193-0001LF" H 2400 3700 60  0001 L CNN
F 3 "http://www.amphenol-icc.com/media/wysiwyg/files/drawing/10118193.pdf" H 2400 3800 60  0001 L CNN
F 4 "609-4616-1-ND" H 2400 3900 60  0001 L CNN "Digi-Key_PN"
F 5 "10118193-0001LF" H 2400 4000 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 2400 4100 60  0001 L CNN "Category"
F 7 "USB, DVI, HDMI Connectors" H 2400 4200 60  0001 L CNN "Family"
F 8 "http://www.amphenol-icc.com/media/wysiwyg/files/drawing/10118193.pdf" H 2400 4300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/amphenol-icc-fci/10118193-0001LF/609-4616-1-ND/2785380" H 2400 4400 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN RCPT USB2.0 MICRO B SMD R/A" H 2400 4500 60  0001 L CNN "Description"
F 11 "Amphenol ICC (FCI)" H 2400 4600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2400 4700 60  0001 L CNN "Status"
	1    2200 3500
	1    0    0    -1  
$EndComp
Text GLabel 2650 3300 2    50   Input ~ 0
5V
Text GLabel 2650 3700 2    50   Input ~ 0
GND
Wire Wire Line
	2500 3300 2650 3300
Wire Wire Line
	2500 3700 2650 3700
$Comp
L esp32_devkit_v1_doit:ESP32_DevKit_V1_DOIT U1
U 1 1 616C92F1
P 5550 3550
F 0 "U1" H 5550 5131 50  0000 C CNN
F 1 "ESP32_DevKit_V1_DOIT" H 5550 5040 50  0000 C CNN
F 2 "esp32_devkit_v1_doit:esp32_devkit_v1_doit" H 5100 4900 50  0001 C CNN
F 3 "https://aliexpress.com/item/32864722159.html" H 5100 4900 50  0001 C CNN
	1    5550 3550
	0    -1   -1   0   
$EndComp
Text GLabel 3850 3650 0    50   Input ~ 0
5V
Text GLabel 7150 3650 2    50   Input ~ 0
GND
Wire Notes Line
	1600 2500 1600 4350
Wire Notes Line
	1600 4350 3100 4350
Wire Notes Line
	3100 4350 3100 2500
Wire Notes Line
	3100 2500 1600 2500
Wire Wire Line
	6950 3650 7150 3650
Wire Wire Line
	4150 3650 3850 3650
Wire Notes Line
	3500 4350 3500 2500
Wire Notes Line
	7550 4350 3500 4350
Text GLabel 4600 2000 0    50   Input ~ 0
5V
Text GLabel 4600 2150 0    50   Input ~ 0
GND
Wire Notes Line
	3500 2500 7550 2500
$Comp
L Connector:Conn_01x04_Male J2
U 1 1 61746ECA
P 4850 1750
F 0 "J2" V 4912 1894 50  0000 L CNN
F 1 "Conn_01x04_Male" V 5003 1894 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 4850 1750 50  0001 C CNN
F 3 "~" H 4850 1750 50  0001 C CNN
	1    4850 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	4650 1950 4650 2000
Wire Wire Line
	4650 2000 4600 2000
Wire Wire Line
	4750 1950 4750 2150
Wire Wire Line
	4750 2150 4600 2150
Wire Wire Line
	4850 2950 4850 1950
Wire Wire Line
	4950 1950 4950 2400
Wire Wire Line
	4950 2400 5550 2400
Wire Wire Line
	5550 2400 5550 2950
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 6176D641
P 6250 1750
F 0 "J3" V 6312 1894 50  0000 L CNN
F 1 "Conn_01x03_Male" V 6403 1894 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6250 1750 50  0001 C CNN
F 3 "~" H 6250 1750 50  0001 C CNN
	1    6250 1750
	0    1    1    0   
$EndComp
Text GLabel 6000 1950 0    50   Input ~ 0
5V
Text GLabel 6000 2200 0    50   Input ~ 0
GND
Wire Wire Line
	5150 2600 5150 2950
$Comp
L Connector:Conn_01x02_Male J4
U 1 1 61779B20
P 7500 1750
F 0 "J4" V 7562 1794 50  0000 L CNN
F 1 "Conn_01x02_Male" V 7653 1794 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7500 1750 50  0001 C CNN
F 3 "~" H 7500 1750 50  0001 C CNN
	1    7500 1750
	0    1    1    0   
$EndComp
Text GLabel 7350 2000 0    50   Input ~ 0
GND
Wire Wire Line
	7400 1950 7400 2000
Wire Wire Line
	7400 2000 7350 2000
Wire Wire Line
	7500 1950 7500 2400
Wire Wire Line
	7500 2400 6350 2400
Wire Wire Line
	6350 2400 6350 2950
$Comp
L Connector:Conn_01x02_Male J5
U 1 1 6178287B
P 8150 2750
F 0 "J5" H 8122 2632 50  0000 R CNN
F 1 "Conn_01x02_Male" H 8122 2723 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8150 2750 50  0001 C CNN
F 3 "~" H 8150 2750 50  0001 C CNN
	1    8150 2750
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x02_Male J6
U 1 1 61783253
P 8150 3150
F 0 "J6" H 8122 3032 50  0000 R CNN
F 1 "Conn_01x02_Male" H 8122 3123 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8150 3150 50  0001 C CNN
F 3 "~" H 8150 3150 50  0001 C CNN
	1    8150 3150
	-1   0    0    1   
$EndComp
Text GLabel 7900 2650 0    50   Input ~ 0
GND
Text GLabel 7900 3050 0    50   Input ~ 0
GND
Wire Wire Line
	7950 2650 7900 2650
Wire Wire Line
	7950 3050 7900 3050
Wire Wire Line
	4950 2750 4950 2950
Wire Wire Line
	5950 2950 5950 2850
Wire Wire Line
	5950 2850 7450 2850
Wire Wire Line
	7450 2850 7450 3150
Wire Notes Line
	4300 1650 5700 1650
Wire Notes Line
	5700 1650 5700 2300
Wire Notes Line
	5700 2300 4300 2300
Wire Notes Line
	4300 2300 4300 1650
Wire Notes Line
	5750 1650 5750 2300
Wire Notes Line
	5750 2300 7050 2300
Wire Notes Line
	7050 2300 7050 1650
Wire Notes Line
	7050 1650 5750 1650
Wire Notes Line
	7100 1650 7100 2300
Wire Notes Line
	7100 2300 8250 2300
Wire Notes Line
	8250 2300 8250 1650
Wire Notes Line
	8250 1650 7100 1650
Wire Wire Line
	4950 2750 7950 2750
Wire Wire Line
	7450 3150 7950 3150
Wire Notes Line
	7600 2500 8900 2500
Wire Notes Line
	8900 2500 8900 2800
Wire Notes Line
	8900 2800 7600 2800
Wire Notes Line
	7600 2800 7600 2500
Wire Notes Line
	7600 2900 8900 2900
Wire Notes Line
	8900 2900 8900 3200
Wire Notes Line
	8900 3200 7600 3200
Wire Notes Line
	7600 3200 7600 2900
Text Notes 4300 1650 0    50   ~ 0
Display TM1637
Text Notes 5750 1650 0    50   ~ 0
WS2811 LED Strip
Text Notes 7100 1650 0    50   ~ 0
Buzzer
Text Notes 7600 2500 0    50   ~ 0
Button right
Text Notes 7600 2900 0    50   ~ 0
Button left
Text Notes 3500 2500 0    50   ~ 0
ESP32 Dev Kit
Text Notes 1600 2500 0    50   ~ 0
MicroUSB
Text GLabel 7150 3550 2    50   Input ~ 0
GND
Wire Notes Line
	7550 2400 7550 4350
Wire Wire Line
	6950 3550 7150 3550
$Comp
L Device:R R1
U 1 1 6179B784
P 6250 2100
F 0 "R1" H 6320 2146 50  0000 L CNN
F 1 "R" H 6320 2055 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 6180 2100 50  0001 C CNN
F 3 "~" H 6250 2100 50  0001 C CNN
	1    6250 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 617A56E4
P 6100 2100
F 0 "C1" H 6218 2146 50  0000 L CNN
F 1 "CP" H 6218 2055 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 6138 1950 50  0001 C CNN
F 3 "~" H 6100 2100 50  0001 C CNN
	1    6100 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1950 6100 1950
Connection ~ 6100 1950
Wire Wire Line
	6100 1950 6000 1950
Wire Wire Line
	6250 2600 6250 2250
Wire Wire Line
	5150 2600 6250 2600
Wire Wire Line
	6350 1950 6350 2250
Wire Wire Line
	6100 2250 6050 2250
Wire Wire Line
	6050 2250 6050 2200
Wire Wire Line
	6050 2200 6000 2200
Connection ~ 6100 2250
Wire Wire Line
	6100 2250 6350 2250
$EndSCHEMATC
