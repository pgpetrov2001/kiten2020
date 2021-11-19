init({}); 




function randomInteger(dokolko) {
    return Math.floor(Math.random()*dokolko);
}

let kuli = [];

for (let i=0; i<20; i++) {
    kuli[i] = 20+randomInteger(300);
}

let cvetove = [];

for (let i=0; i<kuli.length; i++) {
    cvetove[i] = 'black';
}

/*let maxGolemina = 0;
let naiGoliamaKula;

for (let i=0; i<kuli.length; i++) {
    if (kuli[i] > maxGolemina) {
        maxGolemina = kuli[i];
        naiGoliamaKula = i;

        //cvetove[i] = 'red';
    }
}*/

let naiDobraKula, naiMnogoOsv=0;

for (let sv=0; sv<kuli.length; sv++) {
    let brOsv = 0, naiGoliamaDosega = 0;
    for (let i=sv-1; i>=0; i--) {
        if (kuli[i] > kuli[sv]) {
            break;
        }
        if (kuli[i] > naiGoliamaDosega) {
            naiGoliamaDosega = kuli[i];
            brOsv++;
        }
    }
    naiGoliamaDosega = 0;
    for (let i=sv+1; i<kuli.length; i++) {
        if (kuli[i] > kuli[sv]) {
            break;
        }
        if (kuli[i] > naiGoliamaDosega) {
            naiGoliamaDosega = kuli[i];
            brOsv++;
        }
    }

    if (brOsv > naiMnogoOsv) {
        naiMnogoOsv = brOsv;
        naiDobraKula = sv;
    }
}

cvetove[naiDobraKula] = 'red';


function draw() {
    for (let i=0; i<kuli.length; i++) {
        context.fillStyle = cvetove[i];
        context.fillRect((canvas.width/kuli.length)*(i+1), 500-kuli[i], canvas.width/kuli.length-20, kuli[i]);
    }
}




