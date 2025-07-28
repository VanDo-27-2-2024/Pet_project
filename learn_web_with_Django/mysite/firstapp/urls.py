from django.urls import path
from . import views

urlpatterns = [
    path('function', views.hello_world),
    path('class', views.hello_world_class.as_view()),
    path('reservation', views.home),
]

