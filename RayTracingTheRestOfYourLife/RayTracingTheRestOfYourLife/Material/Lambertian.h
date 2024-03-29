﻿#pragma once
#include "Material.h"
#include "../config.h"
#include "../Texture/Texture.h"


class Lambertian : public Material {
public:
	/*
	* @param albedo 反射率
	*/
	Lambertian(Ref<Texture> albedo) : albedo(albedo) {}

	/*
	* @brief 生成散射光线
	* @param r_in 入射光线
	* @param info 碰撞信息
	* @param attenuation 当发生散射时, 光强如何衰减, 分为rgb三个分量
	* @param r_out 散射光线
	* @return 是否得到了散射光线
	*/
	virtual bool scatter(const Ray& r_in, const HitInfo& info, Color& attenuation, Ray& r_out) const override;

	/*
	* @brief 生成散射光线
	* @param r_in 入射光线
	* @param info 碰撞信息
	* @param attenuation 当发生散射时, 光强如何衰减, 分为rgb三个分量
	* @param r_out 散射光线
	* @param pdf 重要性采样的pdf取值
	* @return 是否得到了散射光线
	*/
	virtual bool scatter(const Ray& r_in, const HitInfo& info, Color& attenuation, Ray& r_out, double& pdf) const;

	/*
	* @brief 计算散射pdf的取值
	* @param r_in 入射光线
	* @param info 碰撞信息
	* @param r_out 散射光线
	* @return pdf取值
	*/
	virtual double scatter_pdf(const Ray& r_in, const HitInfo& info, const Ray& r_out) const;

private:
	Ref<Texture> albedo;
};

