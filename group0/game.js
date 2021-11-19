let background = 'black';
let topche = 'red';
function drawImage(color, x, y, w, h) {
    context.fillStyle = color;
    context.fillRect(x, y, w, h);
}
init({});

var topcheX = 400, topcheY = 300;

function update() {
    topcheX = topcheX+3;
    topcheY = topcheY+3;
    if (topcheX > 800) {
        topcheX = 0;
    }
    if (topcheY > 600) {
        topcheY = 0;
    }
}

function draw() {
    drawImage(background, 0, 0, 800, 600);
    drawImage(topche, topcheX, topcheY, 40, 40);
}
