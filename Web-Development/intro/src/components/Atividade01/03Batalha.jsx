import akuma from './akuma.jpg'
import link from './link.png'

const Hero = ({name}) => {
    return (
        <div>
            <h1>Nome do heroi: {name}</h1>
            <img src={akuma} alt="The demon akuma"/>
        </div>
    )
}

const Enemy = ({name}) => {
    return (
        <div>
            <h1>Nome do heroi: {name}</h1>
            <img src={link} alt="Zelda Ocarina of Time" width={400}/>
        </div>  
    )
}

const Arena = ({name}) => {
    return (
        <div>
            <h1>Arena: {name}</h1>
            <Hero name="The Demon Akuma" />
            <Enemy name="Link of Zelda Ocarina of Time" />
        </div>
    )
}

const World = (props) => {
    return (
        <div>
            {props.children}
        </div>
    )
}

export {Hero, Enemy, Arena, World}