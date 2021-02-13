$(document).ready(function () {
    $("#theme-selector").on("click", function () {
        let header = $("#header");
        let tDay = "theme-day";
        let tNight = "theme-night";
        let tImage = document.getElementById('theme-image');
        let tButton = document.getElementById('theme-selector');
        if (header.hasClass(tDay)) {
            let theme = $(".theme-day")
            let tBody = $(".body-day")
            themeChanger(theme, tDay, tNight); // Changes theme for footer and navBar
            tImage.src = "Resources/moon.png";
            tButton.className = "btn btn-outline-secondary";
            themeChanger(tBody, "body-day", "body-night"); // Changes body theme
        } else if (header.hasClass(tNight)) {
            let theme = $(".theme-night")
            let tBody = $(".body-night")
            themeChanger(theme, tNight, tDay); // Changes theme for footer and navBar
            tImage.src = "Resources/sun.png";
            tButton.className = "btn btn-outline-warning";
            themeChanger(tBody, "body-night", "body-day"); // Changes body theme
        } else {
            console.log("Error theme");
        }
    });
});

function themeChanger(object, oldTheme, newTheme) {
    object.each(function (indice, val) {
        $(val).toggleClass(`${oldTheme} ${newTheme}`);
    });
};

$(document).ready(function () {
    $('[data-toggle="tooltip"]').tooltip()
});