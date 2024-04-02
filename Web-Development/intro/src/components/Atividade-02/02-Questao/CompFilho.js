import PokemonContexto from "./PokeContext";
import CompNeto from "./CompNeto"
import { useContext } from "react";

const CompFilho = () => {

    const number = useContext(PokemonContexto)

    return (
        <div>
            <h1>Componente Filho</h1>
            <img 
                src={`https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${number + 1}.png`}
                style={{width: "320px"}}
                alt="pokemon aleatorio"
            />
            <CompNeto></CompNeto>
        </div>
    )
}

export default CompFilho