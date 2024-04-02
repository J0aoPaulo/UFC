const { useState } = require("react")

const Pokemon = () => {
    let url = "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/"
    const [contador, setContador] = useState(1)

    const incrementarContador = () => {
        setContador(contador => contador + 1)
    }

    const decrementarContador = () => {
        setContador(contador => contador - 1)
    }

    return (
        <>
            <h2>Pokemon ID: {contador}</h2>
            <img
            src={url + contador + ".png"}
            alt="Pokemon aleatório"
            width={200}
            />
            <button onClick={() => incrementarContador()}>
                Incrementar Pokemon
            </button>

            <button onClick={() => decrementarContador()}>
                Decrementar Pokemon
            </button>
        </>
    )
}

export default Pokemon