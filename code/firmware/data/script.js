async function toogleLight(element) {
    if (element.checked) {
        await fetch("/lamp/on");
    } else {
        await fetch("/lamp/off");
    }
}

async function setIntensity(element) {
    await fetch("/lamp/intenstiy?value=" + element.value);
}

async function setRGB(element, color) {
    await fetch("/lamp/color?" + color + "=" + element.value);
}