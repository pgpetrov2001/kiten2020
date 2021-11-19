let background = 'black';
let topche = 'red';
function drawImage(color, x, y, w, h) {
    context.fillStyle = color;
    context.fillRect(x, y, w, h);
}
init({});

var topcheNadiasnost = 400, topcheNadolnust = 300;
var posoka = 0;

function update() {
    if (posoka == 0) {
        topcheNadolnust=topcheNadolnust+2;
        topcheNadiasnost=topcheNadiasnost+2;
    }
    if (posoka == 1) {
        topcheNadolnust=topcheNadolnust-2;
        topcheNadiasnost=topcheNadiasnost+2;
    }
    if (posoka == 2) {
        topcheNadolnust=topcheNadolnust-2;
        topcheNadiasnost=topcheNadiasnost-2;
    }
    if (posoka == 3) {
        topcheNadolnust=topcheNadolnust+2;
        topcheNadiasnost=topcheNadiasnost-2;
    }
//posoka 0 oznacava dolu i diasno
//posoka 1 oznacava gore i diasno
//posoka 2 oznacava gore i liavo
//posoka 3 oznacava dolu i liavo
    if (topcheNadolnust > 560) { // izliza otdolu
        if (posoka == 0) {
            posoka = 1;
        }
        if (posoka == 3) {
            posoka = 2;
        }
    }
    if (topcheNadolnust < 0) {
        if (posoka == 1) {
            posoka = 0;
        }
        if (posoka == 2) {
            posoka = 3;
        }
    }
    if (topcheNadiasnost > 760) {
        if (posoka == 0) {
            posoka = 3;
        }
        if (posoka == 1) {
            posoka = 2;
        }
    }
    if (topcheNadiasnost < 0) {
        if (posoka == 2) {
            posoka = 1;
        }
        if (posoka == 3) {
            posoka = 0;
        }
    }
}




/*
function update() {
    if (posoka == 0) {
        topcheNadiasnost = topcheNadiasnost+3;
        topcheNadolnust = topcheNadolnust+3;
    }
    if (posoka == 1) {
        topcheNadiasnost = topcheNadiasnost+3;
        topcheNadolnust = topcheNadolnust-3;
    }
    if (posoka == 2) {
        topcheNadiasnost = topcheNadiasnost-3;
        topcheNadolnust = topcheNadolnust-3;
    }
    if (posoka == 3) {
        topcheNadiasnost = topcheNadiasnost-3;
        topcheNadolnust = topcheNadolnust+3;
    }

    if (topcheNadiasnost < 0) {
        if (posoka == 3) {
            posoka = 0;
        }
        if (posoka == 2) {
            posoka = 1;
        }
    }
    if (topcheNadiasnost+40 > 800) {
        if (posoka == 1) {
            posoka = 2;
        }
        if (posoka == 0) {
            posoka = 3;
        }
    }
    if (topcheNadolnust < 0) {
        if (posoka == 2) {
            posoka = 3;
        }
        if (posoka == 1) {
            posoka = 0;
        }
    }
    if (topcheNadolnust+40 > 600) {
        if (posoka == 0) {
            posoka = 1;
        }
        if (posoka == 3) {
            posoka = 2;
        }
    }
}*/

function draw() {
    drawImage(background, 0, 0, 800, 600);
    drawImage(topche, topcheNadiasnost, topcheNadolnust, 40, 40);
}
