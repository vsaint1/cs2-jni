package com.vsantos1.web;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import com.vsantos1.web.engine.CEngine;

@SpringBootApplication
public class WebApplication {

	public static void main(String[] args) {
		CEngine engine = new CEngine();
		SpringApplication.run(WebApplication.class, args);
		engine.start();

	}

}
