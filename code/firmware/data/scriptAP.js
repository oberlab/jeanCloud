async function setWifi() {
    const ssid = document.getElementById("wifi-ssid").value.trim();
    const password = document.getElementById("wifi-password").value.trim();

    if (ssid.length > 0 && password.length > 0) {
        await fetch("/wifi?ssid=" + encodeURI(ssid) + "&password=" + encodeURI(password));
    }
}