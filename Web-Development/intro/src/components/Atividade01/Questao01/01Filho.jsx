const Filho = ({altura, peso}) => {

    const calculoIMC = (altura, peso) => peso/(altura * altura)

    const imc = calculoIMC(altura, peso)

    function mensagem(imc) {
        if(imc < 18) {
            return <h3>Abaixo do peso</h3>
        } else if(imc > 25) {
            return <h3>Acima do peso</h3>
        } else 
            return <h3>Peso ideal</h3>
    }

    return (
        <div>
            <h1>Calculo do IMC</h1>
            <h2> Resultado do IMC: {imc.toFixed(2)}</h2>
            {mensagem(imc)}
        </div>
    )
}

export default Filho