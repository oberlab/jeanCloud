EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "JeanCloud PCB (for milling)"
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
P 1700 2100
F 0 "J1" H 1764 2845 60  0000 C CNN
F 1 "10118193-0001LF" H 1764 2739 60  0000 C CNN
F 2 "digikey-footprints:USB_Micro_B_Female_10118193-0001LF" H 1900 2300 60  0001 L CNN
F 3 "http://www.amphenol-icc.com/media/wysiwyg/files/drawing/10118193.pdf" H 1900 2400 60  0001 L CNN
F 4 "609-4616-1-ND" H 1900 2500 60  0001 L CNN "Digi-Key_PN"
F 5 "10118193-0001LF" H 1900 2600 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 1900 2700 60  0001 L CNN "Category"
F 7 "USB, DVI, HDMI Connectors" H 1900 2800 60  0001 L CNN "Family"
F 8 "http://www.amphenol-icc.com/media/wysiwyg/files/drawing/10118193.pdf" H 1900 2900 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/amphenol-icc-fci/10118193-0001LF/609-4616-1-ND/2785380" H 1900 3000 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN RCPT USB2.0 MICRO B SMD R/A" H 1900 3100 60  0001 L CNN "Description"
F 11 "Amphenol ICC (FCI)" H 1900 3200 60  0001 L CNN "Manufacturer"
F 12 "Active" H 1900 3300 60  0001 L CNN "Status"
	1    1700 2100
	1    0    0    -1  
$EndComp
Text GLabel 2150 1900 2    50   Input ~ 0
5V
Text GLabel 2150 2300 2    50   Input ~ 0
GND
Wire Wire Line
	2000 1900 2150 1900
Wire Wire Line
	2000 2300 2150 2300
$Comp
L esp32_devkit_v1_doit:ESP32_DevKit_V1_DOIT U1
U 1 1 616C92F1
P 5050 2150
F 0 "U1" H 5050 3731 50  0000 C CNN
F 1 "ESP32_DevKit_V1_DOIT" H 5050 3640 50  0000 C CNN
F 2 "esp32_devkit_v1_doit:esp32_devkit_v1_doit" H 4600 3500 50  0001 C CNN
F 3 "https://aliexpress.com/item/32864722159.html" H 4600 3500 50  0001 C CNN
	1    5050 2150
	0    -1   -1   0   
$EndComp
Text GLabel 3350 2250 0    50   Input ~ 0
5V
Text GLabel 6650 2250 2    50   Input ~ 0
GND
Wire Notes Line
	1100 1100 1100 2950
Wire Notes Line
	1100 2950 2600 2950
Wire Notes Line
	2600 2950 2600 1100
Wire Notes Line
	2600 1100 1100 1100
Wire Wire Line
	6450 2250 6650 2250
Wire Wire Line
	3650 2250 3350 2250
Wire Notes Line
	3000 2950 3000 1100
Wire Notes Line
	3000 1100 7050 1100
Wire Notes Line
	7050 1100 7050 2950
Wire Notes Line
	7050 2950 3000 2950
$EndSCHEMATC
