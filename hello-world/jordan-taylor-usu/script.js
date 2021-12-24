var count = 0;
const message = 'Hello, world!';
var letters = Array.from(message.replace(/\W/g, ''));

document.title = message;
document.getElementById("letters").innerHTML = message;

function changeSVG() {
    var svgImage = document.getElementById("asl");
    removeAnimation(svgImage);
    var letter = letters[count % 10];
    svgImage.src = "images/alphabet/" + letter.toLowerCase() + ".svg";
    svgImage.alt = "asl letter " + letter;
    highlightLetter(count);
    count++;
}

// remove animation after first click
function removeAnimation(svgImage) {
    if (svgImage.src != "images/hand-colored-r.svg") {
        svgImage.className = "hand";
    }
}

// highlight the current corresponding letter
function highlightLetter(count) {
    var colorText = "";
    for (var i = 0; i < 5; i++) {
        if (i == count % 10) {
            colorText += "<span style=\"color: red;\">" + letters[i] + "</span>"
        }
        else {
            colorText += letters[i];
        }
    }
    colorText += ", ";
    for (var i = 5; i < 10; i++) {
        if (i == count % 10) {
            colorText += "<span style=\"color: red;\">" + letters[i] + "</span>"
        }
        else {
            colorText += letters[i];
        }
    }
    colorText += "!";
    document.getElementById("letters").innerHTML = colorText;
}






