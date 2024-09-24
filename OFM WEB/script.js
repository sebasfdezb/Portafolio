let navbar = document.querySelector('nav');
let menuLinks = document.getElementById("menu-links");

function toogleMenu(){
	menuLinks.classList.toggle('show-menu');
}

window.onscroll = function() {
    if (window.scrollY > 0) {
        navbar.style.background = '#1f1f1f';
    } else {
        navbar.style.background = 'transparent';
    }
};
