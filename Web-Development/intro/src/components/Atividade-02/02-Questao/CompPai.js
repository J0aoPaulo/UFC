import PokemonContexto from "./PokeContext"
import CompFilho from "./CompFilho"

const CompPai = () => {

    const number = 10

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
            </div>
        </PokemonContexto.Provider>
    )
}

export default CompPai