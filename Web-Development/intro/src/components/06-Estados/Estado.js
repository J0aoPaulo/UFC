import { useState } from "react"

const Estado = () => {
    let [contador, setContador] = useState(0)

    const incrementarContador = () => {
        setContador(contador => contador + 1)
    }

    return (
        <>
        <h2>Contador: {contador}</h2>
        <button onClick={() => incrementarContador()}>
            IncrementarContador!
        </button>
        </>
    )
}

export default Estado