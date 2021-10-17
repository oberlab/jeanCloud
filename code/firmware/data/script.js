async function toogleLight(element) {
    if (element.checked) {
        await fetch("/lamp/on");
    } else {
        await fetch("/lamp/off");
    }
}

async function setIntensity(element) {
    document.getElementById("intensity-slider-value").innerHTML = element.value;
    await fetch("/lamp/intenstiy?value=" + element.value);
}

async function setRGB(element, color) {
    document.getElementById(color + "-slider-value").innerHTML = element.value;
    await fetch("/lamp/color?" + color + "=" + element.value);
}

async function toogleAlarm(element) {
    if (element.checked) {
        await fetch("/alarm/on");
    } else {
        await fetch("/alarm/off");
    }
}

async function setAlarm() {
    const hour = document.getElementById("wakeup-hour").value;
    const minute = document.getElementById("wakeup-minute").value;

    if ((hour >= 0 && minute >= 0) && (hour <= 23 && minute <= 59)) {
        await fetch("/alarm/set?hour=" + hour + "&minute=" + minute);
    }
}

async function setDisplayIntensity(element) {
    document.getElementById("display-slider-value").innerHTML = element.value;
    await fetch("/display/intenstiy?value=" + element.value);
}