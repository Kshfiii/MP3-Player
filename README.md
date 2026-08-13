# MP3 Player
<img width="1000" height="350" alt="MP3 Player" src="https://github.com/user-attachments/assets/ea8db882-3fad-453b-8f50-3c0bc08042c8" />
 A strawberry-shortcake themed MP3 player built around the DF player mini, and supported by the Xiao Esp32 C3. 

 ## About
 This is a fully self-contained MP3 Player with onboard LiPo charging, a boost-converted 5V motor supply, and a DFPlayer Mini for audio playback on a custom PCB. The xiao handles the pause/play logic via UART communication with the DF player, it was also used because of the in-built BMS and direct charging support.

### Schematics
<img width="500" alt="image" src="https://github.com/user-attachments/assets/71f49582-1600-461b-8a21-90cb123326c1" />

### PCB 
<img  height="300" alt="image" src="https://github.com/user-attachments/assets/0d391b64-e90c-4d56-b2c4-abd5767f9f3a" />
<img  height="300" alt="image" src="https://github.com/user-attachments/assets/797c4320-0ec2-443f-a6b1-ce288a3acc8d" />
<img  height="300" alt="image" src="https://github.com/user-attachments/assets/421be4e8-32e8-4f08-a45d-e870d0377b0c" />

### CAD
[Onshape file](https://cad.onshape.com/documents/b89701995e34a629cb20daf8/w/a087d5ccfa9ba9747f812881/e/695f8d85722ae4ab0145bd85)


<img width="500"  alt="image" src="https://github.com/user-attachments/assets/a1597531-48e1-445c-9db6-76ea7f6a9713" />
<img width="500"  alt="image" src="https://github.com/user-attachments/assets/361a6073-81c6-4869-b7a8-84ad9a7fff78" />

## Assembly
Put the components into their respective spots in the PCB. Put the circular parts into the two holes and then put in the speakers. Add tactile switches to the square placeholder and put the pink buttons on them. Now, add brass inserts onto the back of the Mp3 player and fix the back with screws. 

## Usage & Features

  1. Charge via the USB-C port on the XIAO ESP32-C3
  2. Power on using the slide switch
  3. short press left button for previous song, long press to increase volume
  4. short press right button for next song, long press to decrease volume
  5. Press middle button to pause/play


## Note
1. Attach lipo batter to GND and BATT+ pins on the underside of the Esp32. 
2. Upload audio files to sd card in format, 
   <pre> SD_CARD/
     ├── 0001.mp3
     ├── 0002.mp3
     ├── 0003.mp3
     └── 0004.mp3
   </pre>


## Component List

  1. Seeed Studio XIAO ESP32-C3
  2. DFPlayer Mini (YX5200)
  3. MT3608 Boost Converter IC
  4. AMS1117-5.0 LDO Regulator
  5. 8Ω 1W Speaker
  6. Tactile Switch
  7. 3.7V LiPo Battery

## Bill of Materials
| Component | Quantity | Est. Cost (USD) | Purchase Links | 
| :--- | :---: | :--- | :--- | 
| **Seeed Studio XIAO ESP32-C**| 1 | $11.50 |[Link](https://www.aliexpress.com/item/1005009855437801.html?spm=a2g0o.detail.0.0.378eYyHPYyHPz5&mp=1&pdp_npi=6%40dis%21USD%21USD%2011.43%21USD%2010.93%21%21USD%2010.93%21%21%21%40212e508f17759555552744763e9213%2112000050381761106%21ct%21PK%21-1%21%211%210%21) | 
| **DFPlayer Mini** | 1 | $5.50 | [Link](https://www.aliexpress.com/item/1005011540339952.html?spm=a2g0o.detail.0.0.4b1akxSAkxSANK&mp=1&pdp_npi=6%40dis%21USD%21USD%205.19%21USD%201.99%21%21USD%201.99%21%21%21%40212e520d17760065522677760e7f39%2112000055866842276%21ct%21PK%21-1%21%211%210%21)| 
| **MT3608 Boost Converter IC** | 1 | $1.20 | [Link](https://www.aliexpress.com/item/1005008853748359.html?spm=a2g0o.detail.0.0.378eYyHPYyHPz5&mp=1&pdp_npi=6%40dis%21USD%21USD%202.73%21USD%202.23%21%21USD%202.23%21%21%21%40212e508f17759555552744763e9213%2112000046953414150%21ct%21PK%21-1%21%211%210%21) | 
| **AMS1117-5.0 LDO Regulator** | 1 | $2.50 | [Link](https://www.aliexpress.com/item/1005002487704059.html?spm=a2g0o.productlist.main.4.2196rhF6rhF6yu&aem_p4p_detail=20260411180108338023986275640001084750&algo_pvid=16ee6a6a-aaf1-43e2-94e3-907dfa61e2f0&algo_exp_id=16ee6a6a-aaf1-43e2-94e3-907dfa61e2f0-3&pdp_ext_f=%7B%22order%22%3A%223440%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%212.59%212.09%21%21%212.59%212.09%21%402151e6dc17759556679336660e6cfb%2112000020837902169%21sea%21PK%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A12fde4ed%3Bm03_new_user%3A-29895%3BpisId%3A5000000203713833&curPageLogUid=jNloBkgONfbe&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005002487704059%7C_p_origin_prod%3A&search_p4p_id=20260411180108338023986275640001084750_1) | 
| **8Ω 1W Speaker** | 1 | $1.70 | [Link](https://www.aliexpress.com/item/1005008660223571.html?spm=a2g0o.detail.0.0.173cVO5QVO5QJV&mp=1&pdp_npi=6%40dis%21USD%21USD%204.39%21USD%201.70%21%21USD%201.70%21%21%21%402151e6dc17759543473957645e6ce1%2112000046135720888%21ct%21PK%21-1%21%211%210%21) | 
| **Tactile Switch** | 3 | $1.50 | [Link](https://digilog.pk/products/12-x-12mm-x-7-5mm-push-button-in-pakistan-en?variant=44490991370518 )| 
| **PCB** | 1 | $6.00 | [Link](https://jlcpcb.com/)| 
| **Total Build Cost:** |  | **~$30.00** |

#
Happy Building :)
