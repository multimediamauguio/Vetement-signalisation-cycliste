# Vetement-signalisation-cycliste  
![IMG_20220625_114429667](https://user-images.githubusercontent.com/108124823/175769313-4addca8f-dc7b-4859-92a0-b45696a9cf39.jpg)
![harnais](https://user-images.githubusercontent.com/108124823/175770679-75e8b311-4be9-464f-85f0-945ea592a196.gif)

![clignotant2](https://user-images.githubusercontent.com/108124823/175512643-5c798f9b-81e3-4ad1-9dbe-0f052b269e5d.gif)
![Ensemble guidon](https://user-images.githubusercontent.com/108124823/175767701-7057224c-7b3c-4e59-a178-898d37f16709.JPG)
![ensemble harnais](https://user-images.githubusercontent.com/108124823/175767705-33e753d2-a4e4-4871-93cb-6c4ea6533d2a.JPG)


Projet réalisé à la médiathèque Gaston Baissette de Mauguio de décembre 2021 à juin 2022  

L’atelier porte sur la réalisation d’un dispositif de signalisation de changement de direction et de freinage pour les utilisateurs de vélo.
Cet objet à vocation à être installés de manière simple et rapide sur l’utilisateur et sur le vélo et doit permettre :  
d'avertir (avant et arrière), lors de vos intentions de tourner et ou bien de freiner.

Caractéristiques du dispositif :  

•	Solide (résister à une chute),  
•	léger,  
•	utilisable sur tout vêtement,  
•	facile à utiliser,  
•	attirer l’œil, un objet engageant,  
•	Avoir une bonne autonomie et être rechargeable.  
•	Visible à 50m  
•	Respecter les couleurs habituelles du clignotant et du frein  
•	Étanche  
•	Le dispositif sera libre de droits et reproductible  
  
_Composants nécessaires :_  
[Microcontrôleur LOLIN D32](https://www.aliexpress.com/item/32808551116.html?spm=a2g0o.cart.0.0.5c353c006lJBEE&mp=1)  
[Bande LED 5m 30leds/m](https://www.aliexpress.com/item/32336809966.html?spm=a2g0o.cart.0.0.5c353c006lJBEE&mp=1)  
[Platine de prototypage](https://www.aliexpress.com/item/765383366.html)  
[Condensateur 1000 µF](https://www.amazon.fr/gp/product/B07X3LYPPG/)  
[Joystick à bascule](https://www.amazon.fr/gp/product/B07QM88HP2/)  
[Batterie Lipo 2000 mAh](https://hobbyking.com/en_us/turnigy-2000mah-1s-1c-lipoly-w-2-pin-jst-ph-connector.html)  
[Cable silicone 28 AWG](https://www.aliexpress.com/item/32791720338.html)  
[Lot Broches Femelles](https://www.aliexpress.com/item/4000523047541.html)  
[Transmetteur / Récepteur RF 433Mhz](https://www.aliexpress.com/store/5435161)  
[support pile cr2032](https://www.amazon.fr/gp/product/B07MJG6XZR/)  
[Module de capteur MPU6050](https://www.aliexpress.com/store/910708006)  
[Tissu imperméable jaune uni](https://www.mondialtissus.fr/tissu-impermeable-jaune-uni-152697.html)  
[Boucles réglables](https://www.mondialtissus.fr/boucles-reglables-noires-en-plastique-32-mm-131007.html)  
[Boucles à ouverture rapide](https://www.mondialtissus.fr/boucles-a-ouverture-rapide-noires-en-plastique-30-mm-130987.html)  
[Ruban réfléchissant](https://www.mondialtissus.fr/ruban-reflechissant-20-mm-155143.html)  
[Sangles](https://www.mondialtissus.fr/sangle-coton-renforcee-marine-30mm-251337.html)  
[Velcro](https://www.mondialtissus.fr/bande-agrippante-a-coudre-20mm-noir-20130.html)  
[Velcro](https://www.mondialtissus.fr/bande-agrippante-a-coudre-20mm-noir-20129.html)  

Assemblage des composants :  

![compoBoitierHarnais](https://user-images.githubusercontent.com/108124823/175767891-cad5177b-4b30-4454-b5b3-43a6a9598615.jpg)  
![CompoGuidon](https://user-images.githubusercontent.com/108124823/175767980-3adfa1d2-791b-49da-a528-3742132fd055.jpg)  
![Assemblage_Guidon_4](https://user-images.githubusercontent.com/108124823/175767998-2595ccde-ec34-454a-b924-be23cc0ae792.jpg)  
![Assemblage_Guidon_3](https://user-images.githubusercontent.com/108124823/175768008-ed8f8d25-5d03-4398-a11d-af3a2e2e7f47.jpg)  


Branchements :  
  
Boîtier harnais  
MPU6050	--> Lolin D32  
SDA 	--> 	SDA  
SCL 	--> 	SCL  
GND	  --> 	GND  
VCC	  --> 	3V  

Condensateur 	-->	 LolinD32  
'+ 		--> 	3V  
'- 		--> 	GND  
 
Lolin	-->	Led  
17 	--> 	Led  
GND 	--> 	GND  
3v 	--> 	+5V  

Lolin	-->	Led  
16 	--> 	Led  
GND	 --> 	GND  
3v 	--> 	+5V  

Récepteur radio	--> Lolin D32  
'+ 		--> 	3V  
'- 		--> 	GND  
D0 		--> 	32  
D1 		--> 	33  
D2		--> 	25  
D3		--> 	26  
  
Boîtier guidon  

Joystick 	-->	Radio		<--	Pile  
Com 		--> 	-		<--	-  
			+		<--	+		  
UP		-->	4  
Dwn		-->	3  
Let		-->	2  
Rht		-->	1  
Mid		-->	1, 2, 3 ou 4  
SET  
RST  









![Branchement_leds2](https://user-images.githubusercontent.com/108124823/175767532-a591395b-0c78-4f4d-bc59-54929e9604a4.jpg)  
![Branchements_harnais](https://user-images.githubusercontent.com/108124823/175768027-864a68fd-2716-4991-8578-68a4b3f28c3a.png)

![IMG_20220625_105534532](https://user-images.githubusercontent.com/108124823/175767438-08208da6-510f-4b4f-8830-1512018529d4.jpg)  
![Branchements_guidon](https://user-images.githubusercontent.com/108124823/175766047-cfd040e8-0f04-480e-ac1d-e920cfef08b5.png)  


