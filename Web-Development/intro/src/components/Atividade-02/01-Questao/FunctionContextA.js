import FunctionContextB from "./FunctionContextB"
import FunctionContextC from "./FunctionContextC"

import ColorTheme from "./MyColorContext"

const FunctionContextA = () => {

    const cores = {bkgA: "green", bkgB: "purple", bkgC: "yellow", bkgD: "blue"}

    return (
         <ColorTheme.Provider value={cores}>
            <h1 style={{ backgroundColor: cores.bkgA}}> Contexto A </h1>
            <FunctionContextB />
            <FunctionContextC />
         </ColorTheme.Provider>
    )
}

export default FunctionContextA