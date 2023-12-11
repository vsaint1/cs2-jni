package com.vsantos1.web.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.servlet.ModelAndView;

import com.vsantos1.web.engine.CAimbotConfig;
import com.vsantos1.web.engine.CEngine;
import com.vsantos1.web.engine.CEspConfig;
import com.vsantos1.web.engine.CMiscConfig;

@Controller
public class MenuController {

    @GetMapping("/menu")
    public ModelAndView menu(CAimbotConfig aimConfig, CEspConfig espConfig,CMiscConfig miscConfig) {


        CEngine engine = new CEngine();
        ModelAndView mv = new ModelAndView("views/menu");
        mv.addObject("aimConfig", aimConfig);
        mv.addObject("espConfig", espConfig);
        mv.addObject("miscConfig", miscConfig);
        mv.addObject("pid", engine.getProcessId());

        return mv;

    }

    @PostMapping("/save-config")
    public ModelAndView config(@ModelAttribute CAimbotConfig aimConfig, @ModelAttribute CEspConfig espConfig,@ModelAttribute CMiscConfig miscConfig) {

        aimConfig.configure();
        espConfig.configure();
        miscConfig.configure();

        return new ModelAndView("redirect:/menu");

    }

    @PostMapping("/unload")
    public void unload() {
        CEngine engine = new CEngine();
        engine.stop();
    }

}
