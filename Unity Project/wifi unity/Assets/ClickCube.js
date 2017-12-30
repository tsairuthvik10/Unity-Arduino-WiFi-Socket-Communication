// This script writes out a tcp string to the server (Arduino) when the cube is clicked. On and off alternating/based on current status
 
 #pragma strict
 
 var ledOn : boolean = false;              // Set up variables
 
 var testString : String = "1";
 
 var csharpcomponent: ClientSocket;
 
 var num : int = 10;
 
 var statusText : GameObject;
 
 function Start(){
 csharpcomponent = GameObject.Find("Network").GetComponent(ClientSocket);        // Connect to game objects
 statusText = GameObject.Find("LEDStatusText");
 }
 
 function Update (){
 
 
 if ( Input.GetMouseButtonDown(0)){                                                // if the mouse is clicked fire a raycast out from the screen at the co-ordinates of the cursor
 var hit : RaycastHit;
 var ray : Ray = Camera.main.ScreenPointToRay (Input.mousePosition);
 var select = GameObject.Find("ClickCube").transform;
 if (Physics.Raycast (ray, hit, 100.0)){                                            // if the cube is hit by the ray cast run the appropriate function and send the message out through the socket
 
 if (!csharpcomponent.lightStatus) {
     LedON();
 
     }
 
 if (csharpcomponent.lightStatus) {
     LedOFF();
     }
 }
 }
 }
 
 function LedON () {                    
 csharpcomponent.writeSocket("1");        // write out a 1
 yield;                                    // wait for that function to be called before proceeding (prevents a bounce)
 return;
 
 }
 
 function LedOFF () {
 
 csharpcomponent.writeSocket("0");        // write out a 0
 yield;                                    // wait for that function to be called before proceeding (prevents a bounce)
 return;
 }
 
 