import { useContext } from "react";
import PokemonContexto from "./PokeContext";

const CompNeto = () => {
    const number = useContext(PokemonContexto)

    return (
        <div>
            <h1>Componente Neto</h1>
            <img 
                src={`https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${number + 2}.png`}
                style={{width: "320px"}}
                alt="Pokemon aleatorio"
            />
        </div>
    )
}

export default CompNeto