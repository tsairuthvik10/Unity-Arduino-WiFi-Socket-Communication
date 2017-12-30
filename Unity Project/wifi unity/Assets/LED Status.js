// this script checks to see if the light status has changed, then reacts accordingly
 
 
 
 #pragma strict
 
 var csharpcomponent: ClientSocket;                    // set up variables
 var statusText : GameObject;
 var cube : GameObject;
 
 
 function Start () {
 csharpcomponent = GameObject.Find("Network").GetComponent(ClientSocket);        // connect to game objects
 statusText = GameObject.Find("LEDStatusText");
 
 
 }
 
 function Update () {
 
 if (csharpcomponent.lightStatus)                                // if the light status is true (on)
 {
 statusText.GetComponent.<GUIText>().text = "Light is On";                        // change the text
 cube.GetComponent.<Renderer>().material.SetColor ("_Color", Color.green);        // set the cube colour to green
 }
 
 if (!csharpcomponent.lightStatus)                                // if the light status is NOT true (off)
 {
 statusText.GetComponent.<GUIText>().text = "Light is Off";                        // change the text
 cube.GetComponent.<Renderer>().material.SetColor ("_Color", Color.black);        // set the cube colour to black
 }
 
 
 }
