#pragma once
#include "Object.h"
#include "../Material/Material.h"

class RectXY : public Object {
public:
	/*
	* @param x1 x ����Сֵ
	* @param x2 x �����ֵ
	* @param y1 y ����Сֵ
	* @param y2 y �����ֵ
	* @param k	z ��ֵ
	* @param material ����
	*/
	RectXY(double x1, double x2, double y1, double y2, double k, Ref<Material> material)
		: x1(x1), x2(x2), y1(y1), y2(y2), k(k), material(material) {}

	/*
	* @brief �жϹ����Ƿ��뵱ǰ������ײ
	* @param r ����
	* @param t_min ���ߵ���С t ֵ
	* @param t_max ���ߵ���� t ֵ
	* @param info ��ײ����Ϣ
	* @return �Ƿ���ײ
	*/
	virtual bool hit(const Ray& r, double t_min, double t_max, HitInfo& info) const override;

	/*
	* @brief ��ȡ��ǰ����İ�Χ��
	*/
	virtual AABB GetBox() const override;

private:
	Ref<Material> material;
	double x1, x2, y1, y2, k;
};
