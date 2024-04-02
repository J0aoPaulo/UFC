import PokemonContexto from "./PokeContext"
import CompFilho from "./CompFilho"
import { useState } from "react"

const CompPai = () => {

    const [number, setNumber] = useState(1)

    const apertouBotao = () => {
        setNumber(number + 1)
    }
    return (
        <PokemonContexto.Provider value = {number}>
            <div>
                <h1>Componente Pai</h1>
                <img 
                src={`https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${number}.png`}
                style={{width: "320px"}}
                alt="Pokemon aleatorio"
                />
                <CompFilho></CompFilho>
                <button onClick={alert(apertouBotao)}>
                    mudar pokemon
                </button>
            </div>
        </PokemonContexto.Provider>
    )
}

export default CompPai