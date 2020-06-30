document.querySelector('input#s').addEventListener('click', calcular)
document.querySelector('input#s').addEventListener('mouseenter', entrouSomar)
document.querySelector('input#s').addEventListener('mouseout', saiuSomar)
document.querySelector('input#somar').addEventListener('click', mudaSimboloso)
document.querySelector('input#subtrair').addEventListener('click', mudaSimbolosu)

var bot = document.querySelector("input#s")
var simbolo = document.querySelector('div#simbolo')

function mudaSimboloso() {
    simbolo.innerHTML = '+'
}

function mudaSimbolosu() {
    simbolo.innerHTML = '-'
}

function entrouSomar() {
    bot.value = 'Calcular'
}

function saiuSomar() {
    bot.value = 'calcular'
}

function calcular() {

    var re = document.querySelector('div#res')
    var somado = 0
    var n1 = Number(document.querySelector('input#n1').value)
    var n2 = Number(document.querySelector('input#n2').value)


    if (document.querySelector('input#n1').value.legnth != 0 && document.querySelector('input#n2').value.length != 0) {
        if (document.querySelector('input#somar').checked) {
            somado = n1 + n2
        } else if (document.querySelector('input#subtrair').checked) {
            somado = n1 - n2
        }

        re.style.width = '200px'
        re.style.background = 'black'
        re.style.color = 'white'
        re.innerHTML = `Salário total: ${(somado).toLocaleString('pt-br', { style: 'currency', currency: 'BRL' })} \u{1F911}`
        document.querySelector('section#sect').appendChild(prosection)
    } else {
        alert('Está faltando valores')
        re.innerHTML = ''
    }

}