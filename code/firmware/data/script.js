async function toogleLight(element) {
    if (element.checked) {
        await fetch("/lamp/on");
    } else {
        await fetch("/lamp/off");
    }
}

async function setIntensity(element) {
    console.log(element.value);
}