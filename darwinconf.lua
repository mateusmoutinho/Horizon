PROJECT_NAME = "Horizon"
CONTANIZER   = darwin.argv.get_flag_arg_by_index({ "provider", "contanizer" }, 1, "docker")
VERSION      = "0.0.0"
LICENSE      = "MIT"
URL          = "https://github.com/OUIsolutions/Horizon"
DESCRIPITION = "A database with horizontal scalability"
FULLNAME     = "OUI Solutions"
EMAIL        = "mateusmoutinho01@gmail.com"
SUMARY       = ""
LAUNGUAGE    = "c"

REPLCERS = {
    ["PROJECT_NAME"] = "Horizon"
}

-- Load all build recipes from builds/ directory
darwin.load_all("builds")