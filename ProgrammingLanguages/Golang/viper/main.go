package main

import (
	"fmt"
	"github.com/spf13/viper"
)


func main() {
    viper.SetConfigName("config")
    viper.AddConfigPath("config")
    err := viper.ReadInConfig()
    if err != nil {
        panic(fmt.Errorf("Error reading config file: %s\n", err))
    }

    fmt.Println("title:", viper.GetInt("title"))
}
