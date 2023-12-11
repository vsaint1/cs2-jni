package com.vsantos1.web.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.servlet.ModelAndView;

import com.vsantos1.web.engine.CAimbotConfig;

@Controller
public class MenuController {

    @GetMapping("/menu")
    public ModelAndView menu() {
        CAimbotConfig config = new CAimbotConfig();
        ModelAndView mv = new ModelAndView("views/menu");
        mv.addObject("config", config);
        return mv;

    }

    @PostMapping("/save-config")
    public String config(@ModelAttribute CAimbotConfig config) {

        config.configure();
        return "redirect:/menu";

    }

}
