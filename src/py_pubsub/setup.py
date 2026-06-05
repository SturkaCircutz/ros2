from setuptools import setup

package_name = "py_pubsub"

setup(
    name=package_name,
    version="0.0.1",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="ROS 2 Learner",
    maintainer_email="user@example.com",
    description="Python listener node for the ROS 2 mixed-language pub/sub demo.",
    license="Apache-2.0",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "listener = py_pubsub.listener:main",
        ],
    },
)
