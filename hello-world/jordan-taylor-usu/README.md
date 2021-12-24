# Hello World ASL - Open Source (currently v1)  
The aim of this program is to teach American Sign Language (ASL) in a fun and engaging way. My wife and I recently went out to eat for our fifth anniversary and over the din of the restaurant our waiter used signs as a courtesy which I found exciting and fascinating. My wife is a MSW and uses ASL when working with nonverbal children. We have two infants and incorporate ASL into our parenting style. I have trained our two dogs to respond to basic ASL hand signals such as sit, down, and no, which allows me to communicate to them silently and increases their attention on me. ASL is an increasingly valuable skill for accessibility and convenience, but many ASL resources are expensive, inaccessible, and complicated. I have a background in web developing and 3D modeling, and through this project I hope to combine those and also explore machine learning. Contribute to this open-source project and increase your dev skills to promote ASL learning everywhere! 

## v1 (CURRENT) - basic functionality, proof of concept  
V1 is a responsive webpage built on Bootstrap 5 to display both a message and a scalable vector graphic (svg). The initial svg is animated with CSS. Javascript is used to change the svg on click while highlighting the corresponding displayed letter.  
- greeting animation
- click to progress
- letter highlighting
- 8 letters of the ASL alphabet (a, d, e, h, l, o, r, w)

[Codepen](https://codepen.io/jordan-taylor-usu/pen/rNGYVye) (svgs currently unavailable)
<img src="images/v1-demo.gif" width="100%"/>

## v2 - SVG Transitions
V2 will utilize svg transition animations, condensing all svgs into one in a more functional approach. User-controlled variables will be added via Javascript. The site will also be hosted.  
- host site  
- domain name  
- entire ASL alphabet and numbers
- user variables  
  * skin tone  
  * animation speed  
  * text entry (requires full alphabet)  

### Potential Resources  
- [anime.js](https://animejs.com/)  
- [svgator](https://www.smashingmagazine.com/2021/05/create-edit-animate-svg-svgator3/)  
- [morphsvg](https://greensock.com/morphsvg/)  
- [snap.svg](http://snapsvg.io/)  
- [shapeshifter](https://shapeshifter.design/)  

## v3 - 3D Modeling  
v3 is a complete remake to utilize 3D graphics. A hand model is scanned via photogrammetry and rigged in Blender. The rendering approach is tbd.
- 3D model  
- rigging  

### Potential Resources  
- [vectary](https://www.vectary.com/)  
- three.js  
- bablyon.js  
- blend4web  
- WebGL  
- blender + verge3d  

## v4 - 3D Modeling (contd)  
v4 adds a torso and second hand to the animation to utilize full ASL signs.  
- torso, mirror hand model  
- ASL signs (basic)  
- Additional hand signs - separate lists  
  * dog training  
  * baby basics
  * SCUBA  
  * Ski  
  * military  
  * motorcycle  
- possible VR support  
### Potential Resources  
- mixamo  

## v5 - Machine Learning  
v5 aims to use machine learning to teach the program ASL signs by uploading videos and transcripts. This will automate the progran's vocabulary. When a phrase is entered into the text box, the program should return a valid interpretative response.  
- machine learning  
- user testing and verification   

## v6 - 3rd Party Integration  
v6 will integrate the program with third parties such as bitmoji to allow customizable gifs to be sent over text messages. This is the deployment stage of the program.  
- bitmoji  